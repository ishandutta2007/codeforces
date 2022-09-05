#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 2010;
int n, m, s, t, p[maxn], cnt[maxn][maxn], pr[maxn], lsti[maxn];
ll ds[maxn], dt[maxn], sum[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
ll sf[maxn], sg[maxn][maxn];
vector<pair<int, int>> G[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

int main() {
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w), G[v].emplace_back(u, w);
    }
    auto dijkstra = [&](int s, long long d[maxn]) {
        fill(d + 1, d + n + 1, 1e18), Q.emplace(d[s] = 0, s);
        while (!Q.empty()) {
            auto p = Q.top(); Q.pop();
            if (p.first ^ d[p.second]) continue;
            for (auto e : G[p.second]) if (p.first + e.second < d[e.first]) {
                Q.emplace(d[e.first] = p.first + e.second, e.first);
            }
        }
        vector<ll> V;
        for (int i = 1; i <= n; i++) {
            V.push_back(d[i]);
        }
        sort(V.begin(), V.end());
        V.resize(unique(V.begin(), V.end()) - V.begin());
        for (int i = 1; i <= n; i++) {
            d[i] = lower_bound(V.begin(), V.end(), d[i]) - V.begin();
        }
    };
    dijkstra(s, ds), dijkstra(t, dt);
    for (int i = 1; i <= n; i++) {
        cnt[ds[i]][dt[i]]++, sum[ds[i]][dt[i]] += p[i];
    }
    for (int i = n; ~i; i--) {
        for (int j = n; ~j; j--) {
            cnt[i][j] += cnt[i + 1][j] + cnt[i][j + 1] - cnt[i + 1][j + 1];
            sum[i][j] += sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
        }
    }
    fill(lsti, lsti + n + 1, n);
    memset(sg, -0x3f, sizeof(sg));
    for (int i = n; ~i; i--) {
        memset(sf, 0x3f, sizeof(sf));
        for (int j = n, lstj = n; ~j; j--) {
            if (!cnt[i][j]) {
                f[i][j] = g[i][j] = 0;
            } else {
                while (cnt[i][j] > cnt[lsti[j] - 1][j]) lsti[j]--;
                f[i][j] = sg[lsti[j]][j] + sum[i][j];
                while (cnt[i][j] > cnt[i][lstj - 1]) lstj--;
                g[i][j] = sf[lstj] - sum[i][j];
            }
            sf[j] = min(sf[j + 1], f[i][j] + sum[i][j]);
            sg[i][j] = max(sg[i + 1][j], g[i][j] - sum[i][j]);
        }
    }
    if (f[0][0] > 0) puts("Break a heart");
    else if (!f[0][0]) puts("Flowers");
    else puts("Cry");
    return 0;
}