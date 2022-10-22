#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 4;
const int MOD = 1000 * 1000 * 1000 + 7;

int mod(int n) {
    return (n % MOD + MOD) % MOD;
}

struct Matrix {
    int n, m;
    int a[N][N];
    Matrix(int n_, int m_) {
        n = n_; m = m_;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                a[i][j] = 0;
            }
        }
    }
    int* operator [](int i) {
        return a[i];
    }
    Matrix operator *(Matrix p) {
        Matrix ans(n, p.m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < p.m; ++j) {
                for (int k = 0; k < m; ++k) {
                   ans[i][j] += a[i][k] * p[k][j];
                   ans[i][j] = mod(ans[i][j]);
                }
            }
        }
        return ans;
    }
};

Matrix fp(Matrix m, int pw) {
    Matrix ans(N, N);
    if (pw == 0) {
        for (int i = 0; i < N; ++i) ans[i][i] = 1;
        return ans;
    }
    auto t = fp(m, pw >> 1);
    if (pw % 2 == 0) return t * t;
    else return t * t * m;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    Matrix m(N, N);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            m[i][j] = (i != j);
        }
    }
    m = fp(m, n);

    cout << m[0][0] << '\n';
    return 0;
}