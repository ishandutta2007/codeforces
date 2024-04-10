#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 100010;
int n, m, K, ans, vis[maxn];
ll d[maxn];
bool f[maxn];
vector<tuple<int, int, int>> G[maxn];
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    while (m--) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w, 0), G[v].emplace_back(u, w, 0);
    }
    for (int i = 1, s, y; i <= K; i++) {
        scanf("%d %d", &s, &y);
        G[1].emplace_back(s, y, 1), G[s].emplace_back(1, y, 1);
    }
    memset(d, 0x3f, sizeof(d)), Q.emplace(d[1] = 0, 1);
    while (!Q.empty()) {
        auto p = Q.top(); Q.pop();
        if (p.first ^ d[p.second]) continue;
        for (auto e : G[p.second]) if (d[get<0>(e)] > p.first + get<1>(e)) {
            Q.emplace(d[get<0>(e)] = p.first + get<1>(e), get<0>(e));
        }
    }
    Q.emplace(d[1], 1);
    while (!Q.empty()) {
        int v = Q.top().second; Q.pop();
        if (v > 1 && !f[v]) ans++;
        for (auto e : G[v]) if (d[get<0>(e)] == d[v] + get<1>(e)) {
            if (!get<2>(e)) f[get<0>(e)] = 1;
            if (!vis[get<0>(e)]) Q.emplace(d[get<0>(e)], get<0>(e)), vis[get<0>(e)] = 1;
        }
    }
    printf("%d\n", K - ans);
    return 0;
}