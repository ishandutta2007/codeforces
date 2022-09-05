#include <bits/stdc++.h>
using namespace std;

const int maxn = 110, P = 1000000007;
int n, a[maxn][maxn], u[maxn], v[maxn], b[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int gauss() {
    int s = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j < n; j++) if (a[j][i]) {
            for (int k = 1; k < n; k++) {
                swap(a[i][k], a[j][k]);
            }
            s = P - s; break;
        }
        s = 1LL * s * a[i][i] % P;
        for (int j = i + 1; j < n; j++) {
            int r = 1LL * a[j][i] * qp(a[i][i], P - 2) % P;
            for (int k = i; k < n; k++) {
                a[j][k] = (a[j][k] - 1LL * a[i][k] * r % P) % P;
            }
        }
    }
    return (s + P) % P;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i < n; i++) {
        scanf("%d %d", &u[i], &v[i]);
    }
    for (int i = 1; i <= n; i++) {
        memset(a, 0, sizeof(a));
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                if (j ^ k) a[j][j]++, a[j][k]--;
            }
        }
        for (int j = 1; j < n; j++) {
            a[u[j]][u[j]] += i - 1, a[v[j]][v[j]] += i - 1;
            a[u[j]][v[j]] -= i - 1, a[v[j]][u[j]] -= i - 1;
        }
        b[i] = gauss();
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = qp(i, j - 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) if (a[j][i]) {
            for (int k = 1; k <= n; k++) {
                swap(a[i][k], a[j][k]);
            }
            swap(b[i], b[j]); break;
        }
        for (int j = 1; j <= n; j++) if (i ^ j) {
            int r = 1LL * a[j][i] * qp(a[i][i], P - 2) % P;
            for (int k = i; k <= n; k++) {
                a[j][k] = (a[j][k] - 1LL * a[i][k] * r % P) % P;
            }
            b[j] = (b[j] - 1LL * b[i] * r % P) % P;
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d ", (1LL * b[i] * qp(a[i][i], P - 2) % P + P) % P);
    }
    return 0;
}