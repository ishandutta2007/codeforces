#include <bits/stdc++.h>
using namespace std;

const int maxn = 610;
int n, m, K, tot, a[maxn], mp[maxn], d[maxn];
double p[maxn][maxn];

struct mat {
    double a[110][110];
    mat() { memset(a, 0, sizeof(a)); }

    mat operator * (const mat &o) {
        mat ans;
        for (int i = 1; i <= tot - n; i++) {
            for (int j = 1; j <= tot - n; j++) {
                for (int k = 1; k <= tot - n; k++) {
                    ans.a[i][k] += a[i][j] * o.a[j][k];
                }
            }
        }
        return ans;
    }
} A, B;

int main() {
    scanf("%d %d %d", &n, &m, &K), tot = n;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i]) mp[i] = ++tot;
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        d[u]++, d[v]++;
        p[u][a[v] ? mp[v] : v] -= 1;
        p[v][a[u] ? mp[u] : u] -= 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= tot; j++) p[i][j] /= d[i];
    }
    for (int i = 1; i <= n; i++) {
        p[i][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (abs(p[j][i]) > abs(p[i][i])) swap(p[i], p[j]);
        }
        double t = p[i][i];
        for (int j = 1; j <= tot; j++) p[i][j] /= t;
        for (int j = 1; j <= n; j++) if (i ^ j) {
            for (int k = tot; k >= i; k--) p[j][k] -= p[i][k] * p[j][i];
        }
    }
    for (int i = n + 1; i <= tot; i++) {
        A.a[1][i - n] = p[1][i];
    }
    for (int i = 1; i <= n; i++) if (a[i]) {
        for (int j = n + 1; j <= tot; j++) {
            B.a[mp[i] - n][j - n] = p[i][j];
        }
    }
    for (K -= 2; K; K >>= 1, B = B * B) {
        if (K & 1) A = A * B;
    }
    printf("%.9f\n", abs(A.a[1][tot - n]));
    return 0;
}