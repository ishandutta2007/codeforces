#include <bits/stdc++.h>
using namespace std;

const int maxn = 10010, P = 1000000007;
int n, K, ans = 1;
vector<int> G[maxn];
map<int, int> a[maxn];

int qp(int x, int y) {
    int z = 1;
    for (; y; y >>= 1, x = 1LL * x * x % P) {
        if (y & 1) z = 1LL * z * x % P;
    }
    return z;
}

int main() {
    scanf("%d %d", &n, &K);
    auto add_edge = [&](int u, int v) {
        a[u][u]++, a[v][v]++;
        a[u][v] = a[v][u] = P - 1;
        G[u].push_back(v);
    };
    for (int i = 1; i <= K; i++) {
        for (int j = 1; j < i; j++) add_edge(i, j);
    }
    for (int i = K + 1; i <= n; i++) {
        for (int j = 1, k; j <= K; j++) {
            scanf("%d", &k), add_edge(i, k);
        }
    }
    for (int i = n; i > 1; i--) {
        ans = 1LL * ans * a[i][i] % P;
        int inv = qp(a[i][i], P - 2);
        for (int j : G[i]) {
            int t = P - 1LL * a[j][i] * inv % P;
            for (int k : G[i]) a[j][k] = (a[j][k] + 1LL * t * a[i][k]) % P;
        }
    }
    printf("%d\n", ans);
    return 0;
}