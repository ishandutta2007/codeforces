#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, K, s, a[maxn], d[110][maxn];
vector<int> G[maxn];

int main() {
    scanf("%d %d %d %d", &n, &m, &K, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    while (m--) {
        int u, v; scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    memset(d, -1, sizeof(d));
    for (int i = 1; i <= K; i++) {
        queue<int> Q;
        for (int j = 1; j <= n; j++) {
            if (a[j] == i) d[i][j] = 0, Q.push(j);
        }
        while (!Q.empty()) {
            int v = Q.front(); Q.pop();
            for (int u : G[v]) if (!~d[i][u]) {
                d[i][u] = d[i][v] + 1, Q.push(u);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<int> w;
        for (int j = 1; j <= K; j++) {
            w.push_back(d[j][i]);
        }
        sort(w.begin(), w.end());
        printf("%d ", accumulate(w.begin(), w.begin() + s, 0));
    }
    return 0;
}