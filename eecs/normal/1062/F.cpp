#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, m, ans, f[maxn], d[maxn];
bool ban[maxn];
vector<int> G[maxn], H[maxn];

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), H[v].push_back(u);
    }
    auto topo = [&](vector<int> *G) {
        memset(d, 0, sizeof(d));
        for (int i = 1; i <= n; i++) {
            for (int j : G[i]) d[j]++;
        }
        int tot = 0;
        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (!d[i]) Q.push(i), tot++;
        }
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            if (Q.empty()) f[u] += n - tot;
            if (Q.size() == 1) {
                int v = Q.front();
                bool flag = 0;
                for (int x : G[v]) {
                    if (d[x] == 1) flag = 1;
                }
                if (flag) ban[u] = 1;
                else f[u] += n - tot;
            }
            for (int v : G[u]) if (!--d[v]) {
                Q.push(v), tot++;
            }
        }
    };
    topo(G), topo(H);
    for (int i = 1; i <= n; i++) {
        if (!ban[i] && f[i] >= n - 2) ans++;
    }
    printf("%d\n", ans);
    return 0;
}