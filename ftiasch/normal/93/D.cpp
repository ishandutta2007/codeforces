// Codeforces Beta Round #76
// Problem D -- Flags
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 17, 
      WHITE = 0, BLACK = 1, RED = 2, YELLOW = 3,
      MOD = 1000000007;

struct Matrix {
    int mat[N][N];

    Matrix () {
        memset(mat, 0, sizeof(mat));
    }
};

Matrix operator * (const Matrix &a, const Matrix &b) {
    Matrix c;
    for (int i = 0; i < N; ++ i) {
        for (int j = 0; j < N; ++ j) {
            for (int k = 0; k < N; ++ k) {
                c.mat[i][j] = (c.mat[i][j] + (long long)a.mat[i][k] * b.mat[k][j]) % MOD;
            }
        }
    }
    return c;
}

int ind (int i, int j) {
    return (i << 2) | j;
}

bool isValid (int a, int b) {
    if (a == b) {
        return false;
    }
    if ((a == WHITE and b == YELLOW) or (a == YELLOW and b == WHITE)) {
        return false;
    }
    if ((a == RED and b == BLACK) or (a == BLACK and b == RED)) {
        return false;
    }
    return true;
}

Matrix pow (Matrix a, int n) {
    Matrix result;   
    for (int i = 0; i < N; ++ i) {
        result.mat[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            result = result * a;
        }
        n >>= 1;
        a = a * a;
    }
    return result;
}

int solve (int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 4;
    }    
    int result = 4;
    Matrix a, t;
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            if (isValid(i, j)) {
                a.mat[0][ind(i, j)] += 1;
                a.mat[0][16] += 1;
            }
        }
    }
    for (int i = 0; i < 4; ++ i) {
        for (int j = 0; j < 4; ++ j) {
            for (int k = 0; k < 4; ++ k) {
                if (isValid(i, j) and isValid(j, k)) {
                    if (i == BLACK and j == WHITE and k == RED) {
                        continue;
                    }
                    if (i == RED and j == WHITE and k == BLACK) {
                        continue;
                    }
                    t.mat[ind(i, j)][ind(j, k)] += 1;
                    t.mat[ind(i, j)][16] += 1;
                }
            }
        }
    }
    t.mat[16][16] += 1;
    int temp = ((a * pow(t, n - 2)).mat[0][16]) % MOD;
    if (n >= 3) {
        temp = (temp + (a * pow(t, (n + 1) / 2 - 2)).mat[0][16]) % MOD;
    }
    return (result + (long long)temp * 500000004) % MOD;
}

int main () {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", (solve(r) - solve(l - 1) + MOD) % MOD);
    return 0;
}