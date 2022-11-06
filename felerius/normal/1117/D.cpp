#include <algorithm>
#include <array>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <numeric>
#include <string>
#include <type_traits>
#include <unistd.h>
#include <vector>


using namespace std;

static const uint64_t MOD = 1000000007;

template <class I>
class Matrix {
private:
    size_t size;
    vector<I> data;

public:
    Matrix(size_t size) : size(size), data(size * size) {}

    const I& operator()(size_t x, size_t y) const;
    I& operator()(size_t x, size_t y);

    Matrix operator*(const Matrix& rhs) const;
};

template <class I>
const I& Matrix<I>::operator()(size_t x, size_t y) const {
    return data[y * size + x];
}

template <class I>
I& Matrix<I>::operator()(size_t x, size_t y) {
    return data[y * size + x];
}

template <class I>
Matrix<I> Matrix<I>::operator*(const Matrix& rhs) const {
    Matrix res(size);
    auto& lhs = *this;
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j) {
            for (size_t k = 0; k < size; ++k) {
                res(i, j) += lhs(i, k) * rhs(k, j);
                res(i, j) %= MOD;
            }
        }
    }

    return res;
}

template <class I>
Matrix<I> square_and_multiply(Matrix<I> mat, uint64_t exp, I mod) {
    if (exp == 1) {
        return mat;
    }

    auto exp_mat = square_and_multiply(mat, exp / 2, mod);
    auto res = exp_mat * exp_mat;
    if (exp % 2 == 1) {
        res = res * mat;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);

    uint64_t n;
    size_t m;
    cin >> n >> m;

    Matrix<uint64_t> mat(m);
    mat(0, 0) = 1;
    mat(0, m - 1) = 1;
    for (size_t i = 1; i < m; ++i) {
        mat(i, i - 1) = 1;
    }

    mat = square_and_multiply(mat, n, MOD);
    uint64_t result = 0;
    for (size_t i = 0; i < m; ++i) {
        result += mat(m - 1, i);
    }

    cout << (result % MOD) << '\n';

    return 0;
}