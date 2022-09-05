#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 252, P = 1000000007;
int F, B, p[11], cnt[maxn], coef[maxn];
ll n;

void red(int &x) {
    x += x >> 31 & P;
}

typedef array<array<int, maxn>, maxn> mat;

mat operator + (const mat &A, const mat &B) {
    mat C;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            red(C[i][j] = A[i][j] + B[i][j] - P);
        }
    }
    return C;
}

mat operator * (const mat &A, const mat &B) {
    mat C{};
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) if (A[i][j]) {
            for (int k = 0; k < maxn; k++) if (B[j][k]) {
                C[i][k] = (C[i][k] + 1LL * A[i][j] * B[j][k]) % P;
            }
        }
    }
    return C;
}

mat operator * (const mat &A, int x) {
    mat B;
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            B[i][j] = 1LL * x * A[i][j] % P;
        }
    }
    return B;
}

// https://codeforces.com/gym/102984/submission/130905690
namespace solver {
const int maxn = 500;
int a[maxn][maxn], h[maxn][maxn], p[maxn][maxn], ans[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void characteristic(int n) {
    memcpy(h, a, sizeof(h));
    for (int i = 1; i + 2 <= n; i++) {
        if (!h[i + 1][i]) {
            for (int j = i + 2; j <= n; j++) if (h[j][i]) {
                for (int k = i; k <= n; k++) swap(h[i + 1][k], h[j][k]);
                for (int k = 1; k <= n; k++) swap(h[k][i + 1], h[k][j]);
                break;
            }
        }
        if (!h[i + 1][i]) continue;
        int inv = qp(h[i + 1][i], P - 2);
        for (int j = i + 2; j <= n; j++) if (h[j][i]) {
            int t = 1LL * h[j][i] * inv % P;
            for (int k = i; k <= n; k++) {
                h[j][k] = (h[j][k] + 1LL * h[i + 1][k] * (P - t)) % P;
            }
            for (int k = 1; k <= n; k++) {
                h[k][i + 1] = (h[k][i + 1] + 1LL * h[k][j] * t) % P;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            h[i][j] = (P - h[i][j]) % P;
        }
    }
    for (int i = p[0][0] = 1; i <= n; i++) {
        copy(p[i - 1], p[i - 1] + i, p[i] + 1);
        for (int j = i - 1, v = 1; ~j; j--) {
            int t = 1LL * v * h[j + 1][i] % P;
            for (int k = 0; k <= j; k++) {
                p[i][k] = (p[i][k] + 1LL * p[j][k] * t) % P;
            }
            if (j) v = 1LL * v * (P - h[j + 1][j]) % P;
        }
    }
    copy(p[n], p[n] + n + 1, ans);
}
} // namespace solver

int main() {
    scanf("%d %d %lld", &F, &B, &n);
    for (int i = 1; i <= F; i++) {
        scanf("%d", &p[i]);
    }
    while (B--) {
        int c;
        scanf("%d", &c), cnt[c]++;
    }
    mat tr{};
    for (int i = 0; i <= 250; i++) {
        tr[i][i + 1] = 1, tr[i][0] = cnt[i + 1];
    }
    for (int i = 0; i < maxn; i++) {
        for (int j = 0; j < maxn; j++) {
            solver::a[i + 1][j + 1] = tr[i][j];
        }
    }
    solver::characteristic(maxn);
    auto eval = [&](int k) {
        vector<int> d(2 * maxn);
        d[0] = 1;
        for (int i = 29; ~i; i--) {
            auto tmp = d;
            d.assign(2 * maxn, 0);
            for (int j = 0; j < maxn; j++) {
                for (int k = 0; k < maxn; k++) {
                    d[j + k] = (d[j + k] + 1LL * tmp[j] * tmp[k]) % P;
                }
            }
            if (k >> i & 1) {
                for (int j = 2 * maxn - 1; j; j--) d[j] = d[j - 1];
                d[0] = 0;
            }
            for (int j = 2 * maxn - 1; j >= maxn; j--) {
                for (int k = maxn; ~k; k--) {
                    d[j - k] = (d[j - k] - 1LL * d[j] * solver::ans[maxn - k] % P + P) % P;
                }
            }
        }
        for (int i = 0; i < maxn; i++) {
            red(coef[i] += d[i] - P);
        }
    };
    for (int i = 1; i <= F; i++) {
        eval(p[i]);
    }
    mat sum{}, A{};
    for (int i = 0; i < maxn; i++) A[i][i] = 1;
    for (int i = 0; i < maxn; i++) {
        sum = sum + A * coef[i];
        mat B{};
        for (int j = 0; j < maxn; j++) {
            for (int k = 0; k < maxn; k++) {
                B[j][0] = (B[j][0] + 1LL * A[j][k] * tr[k][0]) % P;
                if (k + 1 == maxn) continue;
                B[j][k + 1] = (B[j][k + 1] + 1LL * A[j][k] * tr[k][k + 1]) % P;
            }
        }
        A = B;
    }
    A = mat{};
    A[0][0] = 1;
    for (; n; n >>= 1, sum = sum * sum) {
        if (n & 1) A = A * sum;
    }
    printf("%d\n", A[0][0]);
    return 0;
}