#include <bits/stdc++.h>
using namespace std;

const int maxn = 610;
int n, m, P, ans = 1, ind[maxn], f[maxn], a[maxn][maxn];
vector<int> ord, G[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d %d", &n, &m, &P);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), ind[v]++;
    }
    vector<int> from, to;
    queue<int> Q;
    for (int i = 1; i <= n; i++) {
        if (!ind[i]) from.push_back(i), Q.push(i);
        if (G[i].empty()) to.push_back(i);
    }
    while (!Q.empty()) {
        int u = Q.front(); Q.pop(), ord.push_back(u);
        for (int v : G[u]) {
            if (!--ind[v]) Q.push(v);
        }
    }
    for (int i = 0; i < from.size(); i++) {
        memset(f, 0, sizeof(f)), f[from[i]] = 1;
        for (int j : ord) {
            for (int k : G[j]) (f[k] += f[j]) %= P;
        }
        for (int j = 0; j < to.size(); j++) {
            a[i][j] = f[to[j]];
        }
    }
    for (int i = 0; i < from.size(); i++) {
        for (int j = i + 1; j < from.size(); j++) if (a[j][i]) {
            swap(a[i], a[j]), ans = (P - ans) % P; break;
        }
        ans = 1LL * ans * a[i][i] % P;
        int inv = qp(a[i][i], P - 2);
        for (int j = i + 1; j < from.size(); j++) if (a[j][i]) {
            int t = P - 1LL * a[j][i] * inv % P;
            for (int k = i; k < from.size(); k++) {
                a[j][k] = (a[j][k] + 1LL * t * a[i][k]) % P;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}