#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int T, n, m, a[maxn];
map<int, int> mp;
map<int, vector<int>> occ;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        mp.clear(), occ.clear();
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]), mp[a[i]]++;
        }
        for (auto &p : mp) {
            occ[p.second].push_back(p.first);
        }
        vector<pair<int, vector<int>>> V;
        for (auto &p : occ) {
            V.emplace_back(p.first, p.second);
        }
        priority_queue<tuple<long long, int, int, int, int>> Q;
        set<pair<int, int>> vis, ban;
        while (m--) {
            int x, y;
            scanf("%d %d", &x, &y);
            ban.emplace(x, y);
        }
        for (int i = 0; i < V.size(); i++) {
            for (int j = i; j < V.size(); j++) {
                Q.emplace(1LL * (V[i].first + V[j].first) * (V[i].second.back() + V[j].second.back()), i, j, V[i].second.size() - 1, V[j].second.size() - 1);
            }
        }
        while (1) {
            assert(!Q.empty());
            auto p = Q.top(); Q.pop();
            int i = get<1>(p), j = get<2>(p), x = get<3>(p), y = get<4>(p);
            int u = V[i].second[x], v = V[j].second[y];
            if (u > v) swap(u, v);
            if (vis.count({u, v})) continue;
            vis.emplace(u, v);
            if (u < v && !ban.count({u, v})) { printf("%lld\n", get<0>(p)); break; }
            if (x) Q.emplace(1LL * (V[i].first + V[j].first) * (V[i].second[x - 1] + V[j].second[y]), i, j, x - 1, y);
            if (y) Q.emplace(1LL * (V[i].first + V[j].first) * (V[i].second[x] + V[j].second[y - 1]), i, j, x, y - 1);
        }
    }
    return 0;
}