#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 200010;
int n, m;
ll f[maxn][2][2];
vector<pair<int, int>> G[maxn];

struct node {
    ll d; int v, i, j;
    bool operator < (const node &o) const { return d > o.d; }
};
priority_queue<node> Q;

int main() {
    scanf("%d %d", &n, &m);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    memset(f, 0x3f, sizeof(f));
    Q.push((node){f[1][0][0] = 0, 1, 0, 0});
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (p.d ^ f[p.v][p.i][p.j]) continue;
        for (auto e : G[p.v]) {
            int u = e.first, w = e.second;
            for (int i = p.i; i < 2; i++) {
                for (int j = p.j; j < 2; j++) {
                    ll d = p.d + w * (1 - (p.i < i) + (p.j < j));
                    if (d < f[u][i][j]) Q.push((node){f[u][i][j] = d, u, i, j});
                }
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        printf("%lld ", f[i][1][1]);
    }
    return 0;
}