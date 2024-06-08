#pragma once
#include "random2024.h"
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace rand16;

namespace Matrix1 {

    float** CreateMatrix(unsigned rc, unsigned cc) {
        if ((rc == 0) || (cc == 0)) {
            return nullptr;
        }
        float** A = new float* [rc];
        for (unsigned i = 0; i < rc; i++) {
            A[i] = new float[cc];
        }
        return A;
    }

    void DeleteMatrix(float** A, unsigned rc) {
        if (A != nullptr) {
            for (unsigned i = 0; i < rc; i++) {
                delete[] A[i];
            }
            delete[] A;
        }
    }

    float** GenerateMatrix(unsigned rc, unsigned cc, float inf, float sup) {
        float** A = CreateMatrix(rc, cc);
        if (A != nullptr) {
            for (unsigned i = 0; i < rc; i++) {
                for (unsigned j = 0; j < cc; j++) {
                    A[i][j] = rand_();
                    std::cout << A[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        return A;
    }

    float** MatrixMultiply(float** A, unsigned arc, unsigned acc, float** B, unsigned brc, unsigned bcc) {
        if ((A == nullptr) || (B == nullptr) || (acc != brc) || (arc == 0) || (bcc == 0)) {
            return nullptr;
        }
        else {
            float** C = CreateMatrix(arc, bcc);
            unsigned i, j, k;
            for (i = 0; i < arc; i++) {
                for (j = 0; j < bcc; j++) {
                    C[i][j] = 0;
                    for (k = 0; k < acc; k++) {
                        C[i][j] += A[i][k] * B[k][j];
                    }
                }
            }
            return C;
        }
    }

    void SwapCols(float** A, unsigned c1, unsigned c2, unsigned rc) {
        if (A != nullptr) {
            for (unsigned i = 0; i < rc; i++) {
                float tmp = A[i][c1];
                A[i][c1] = A[i][c2];
                A[i][c2] = tmp;
            }
        }
    }

    void SwapRows(float** A, unsigned r1, unsigned r2, unsigned rc) {
        if ((A != nullptr) && (rc > r1) && (rc > r2)) {
            float* tmp = A[r1];
            A[r1] = A[r2];
            A[r2] = tmp;
        }
    }

    void ExportMatrix(const char* filename, float** A, unsigned rc, unsigned cc) {
        if (A == nullptr) {
            return;
        }
        else {
            std::ofstream file(filename);
            if (file.is_open()) {
                file.setf(std::ios::fixed);
                file << std::setfill(' ');
                file.precision(7);
                for (unsigned i = 0; i < rc; i++) {
                    for (unsigned j = 0; j < cc; j++) {
                        file << std::setw(10) << A[i][j] << "\t";
                    }
                    file << std::endl;
                }
                file.close();
            }
        }
    }

    void coutMatrix(float** A, unsigned rc, unsigned cc) {
        if (A != nullptr) {
            for (unsigned i = 0; i < rc; i++) {
                for (unsigned j = 0; j < cc; j++) {
                    std::cout << std::setw(10) << A[i][j] << "\t";
                }
                std::cout << std::endl;
            }
        }
    }

    float** gaussSLAE(float** A, float** B, unsigned order) {
        if ((A == nullptr) || (B == nullptr) || (order == 0)) {
            return nullptr;
        }
        else {
            bool flagSU = true;
            unsigned r, i, j, mr, mc;
            float mvalue; // main element value

            float** M = CreateMatrix(order, order + 1);
            float** X = nullptr; // матрица-столбец с решением (если оно сущ. и единственно)
            for (i = 0; i < order; i++) {
                for (j = 0; j < order; j++) {
                    M[i][j] = A[i][j];
                }
                M[i][order] = B[i][0];
            }

            unsigned* ind = new unsigned[order];
            for (i = 0; i < order; i++) {
                ind[i] = i;
            }
            // Прямая прогонка
            // Реализуйте прямую прогонку
            // Обратная прогонка
            // Реализуйте обратную прогонку

            DeleteMatrix(M, order);
            delete[] ind;
            return X;
        }
    }
}
