#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, m, K, ban[maxn], cur[maxn], _ban[maxn], _cur[maxn];
vector<int> G[maxn], ans;

int main() {
    scanf("%d %d %d", &n, &m, &K);
    for (int i = 1, v; i <= K; i++) {
        scanf("%d", &v), ban[v] = _ban[v] = 1;
    }
    while (m--) {
        int u, v;
        scanf("%d %d", &u, &v);
        G[u].push_back(v), G[v].push_back(u);
    }
    for (int i = 1; i <= n; i++) {
        for (int j : G[i]) {
            if (!ban[j]) _cur[i]++;
        }
    }
    auto chk = [&](double x) {
        memcpy(ban, _ban, sizeof(ban));
        memcpy(cur, _cur, sizeof(cur));
        function<void(int)> upd = [&](int v) {
            if (ban[v] || 1.0 * cur[v] / G[v].size() > x - 1e-9) return;
            ban[v] = 1;
            for (int u : G[v]) cur[u]--, upd(u);
        };
        for (int i = 1; i <= n; i++) {
            upd(i);
        }
        ans.clear();
        for (int i = 1; i <= n; i++) {
            if (!ban[i]) ans.push_back(i);
        }
        return !ans.empty();
    };
    double l = 0, r = 1;
    while (r - l > 1e-9) {
        double mid = (l + r) / 2;
        chk(mid) ? l = mid : r = mid;
    }
    chk(l);
    printf("%d\n", ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}