#include <bits/stdc++.h>
using namespace std;

const int maxn = 300010;
int n, w[maxn];
long long mx[maxn];
vector<pair<int, int>> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
    }
    for (int i = 1, u, v, w; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    }
    long long ans = *max_element(w + 1, w + n + 1);
    function<void(int, int)> dfs = [&](int v, int fa) {
        mx[v] = w[v];
        for (auto e : G[v]) if (e.first ^ fa) {
            dfs(e.first, v);
            ans = max(ans, mx[v] + mx[e.first] - e.second);
            mx[v] = max(mx[v], w[v] + mx[e.first] - e.second);
        }
    };
    dfs(1, 0), printf("%lld\n", ans);
    return 0;
}