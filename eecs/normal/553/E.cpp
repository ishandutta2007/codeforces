#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef complex<double> complex_t;
const int maxn = 55, maxm = 115, maxT = 20010;
int n, m, T, x, u[maxm], v[maxm], w[maxm], dist[maxn];
int lim, L, r[2 * maxT];
double e[maxm][maxT], es[maxm][maxT], f[maxn][maxT], g[maxm][maxT];
complex<double> A[2 * maxT], B[2 * maxT];
vector<pair<int, int>> G[maxn];

void init() {
    for (int i = 0; i < lim; i++) {
        r[i] = (r[i >> 1] >> 1) | ((i & 1) << (L - 1));
    }
}

void DFT(complex_t *c, int type) {
    for (int i = 0; i < lim; i++) {
        if (i < r[i]) swap(c[i], c[r[i]]);
    }
    for (int i = 1; i < lim; i <<= 1) {
        complex_t x(cos(M_PI / i), type * sin(M_PI / i));
        for (int j = 0; j < lim; j += i << 1) {
            complex_t y(1, 0);
            for (int k = 0; k < i; k++, y *= x) {
                auto p = c[j + k], q = y * c[i + j + k];
                c[j + k] = p + q, c[i + j + k] = p - q;
            }
        }
    }
    if (type == -1) {
        for (int i = 0; i < lim; i++) c[i] /= lim;
    }
}

int main() {
    scanf("%d %d %d %d", &n, &m, &T, &x);
    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        G[v[i]].push_back({u[i], w[i]});
        for (int j = 1; j <= T; j++) {
            scanf("%lf", &e[i][j]), e[i][j] /= 1e5;
        }
        for (int j = T; j; j--) {
            es[i][j] = es[i][j + 1] + e[i][j];
        }
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;
    fill(dist + 1, dist + n + 1, INT_MAX);
    Q.emplace(dist[n] = x, n);
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (p.first ^ dist[p.second]) continue;
        for (auto &e : G[p.second]) if (dist[e.first] > p.first + e.second) {
            Q.emplace(dist[e.first] = p.first + e.second, e.first);
        }
    }
    for (int i = 1; i < n; i++) {
        fill(f[i], f[i] + T + 1, 1e8);
    }
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == r) {
            for (int i = 1; i <= m; i++) {
                f[u[i]][l] = min(f[u[i]][l], g[i][l] + w[i] + es[i][l + 1] * dist[v[i]]);
            }
            return;
        }
        int mid = (l + r) / 2;
        solve(l, mid);
        for (int i = 1; i <= m; i++) {
            for (lim = 1, L = 0; lim <= r - l; lim <<= 1) L++;
            init(), fill(A, A + lim, 0), fill(B, B + lim, 0);
            copy(f[v[i]] + l, f[v[i]] + mid + 1, A);
            copy(e[i], e[i] + r - l + 1, B);
            DFT(A, 1), DFT(B, 1);
            for (int j = 0; j < lim; j++) A[j] *= B[j];
            DFT(A, -1);
            for (int j = mid + 1; j <= r; j++) g[i][j] += A[j - l].real();
        }
        solve(mid + 1, r);
    };
    solve(0, T);
    printf("%.9f\n", f[1][T]);
    return 0;
}