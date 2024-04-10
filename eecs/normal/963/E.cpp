#include <bits/stdc++.h>
using namespace std;

typedef vector<int> poly;
const int maxn = 110, P = 1000000007;
const int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};
int r, n, tot, a[4], id[maxn][maxn], var[maxn];
poly coef[maxn * maxn], p[maxn];

void red(int &x) {
    x += x >> 31 & P;
}

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

void operator -= (poly &A, const poly &B) {
    if (A.size() < B.size()) A.resize(B.size());
    for (int i = 0; i < A.size(); i++) red(A[i] -= B[i]);
}

poly operator * (poly A, int k) {
    for (int &x : A) x = 1LL * x * k % P;
    return A;
}

int main() {
    scanf("%d %d %d %d %d", &r, &a[0], &a[1], &a[2], &a[3]);
    int sa = 0;
    for (int i = 0; i < 4; i++) {
        red(sa += a[i] - P);
    }
    for (int i = 0, t = qp(sa, P - 2); i < 4; i++) {
        a[i] = 1LL * a[i] * t % P;
    }
    n = 2 * r + 1, memset(id, -1, sizeof(id));
    for (int i = -r; i <= r; i++) {
        for (int j = -r; j <= r; j++) if (i * i + j * j <= r * r) {
            coef[id[i + r][j + r] = tot++].resize(n + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (~id[i][j]) {
            coef[id[i][j]][i] = 1; break;
        }
    }
    for (int j = 0, inv = qp(a[3], P - 2); j < n; j++) {
        for (int i = 0; i < n; i++) if (~id[i][j]) {
            poly q = coef[id[i][j]];
            red(--q[n]);
            for (int k = 0; k < 3; k++) {
                int x = i + dx[k], y = j + dy[k];
                if (x < 0 || x >= n || y < 0 || y >= n || !~id[x][y]) continue;
                q -= coef[id[x][y]] * a[k];
            }
            if (~id[i][j + 1]) coef[id[i][j + 1]] = q * inv;
            else red(q[n] = -q[n]), p[i] = q;
        }
    }
    auto gauss = [&] {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) if (p[j][i]) {
                swap(p[i], p[j]); break;
            }
            int inv = P - qp(p[i][i], P - 2);
            for (int j = i + 1; j < n; j++) if (p[j][i]) {
                int t = 1LL * p[j][i] * inv % P;
                for (int k = i; k <= n; k++) {
                    red(p[j][k] += 1LL * t * p[i][k] % P - P);
                }
            }
        }
        for (int i = n - 1; ~i; i--) {
            var[i] = p[i][n];
            for (int j = i + 1; j < n; j++) {
                red(var[i] -= 1LL * var[j] * p[i][j] % P);
            }
            var[i] = 1LL * var[i] * qp(p[i][i], P - 2) % P;
        }
    };
    gauss();
    int ans = coef[id[r][r]][n];
    for (int i = 0; i < n; i++) {
        red(ans += 1LL * var[i] * coef[id[r][r]][i] % P - P);
    }
    printf("%d\n", ans);
    return 0;
}