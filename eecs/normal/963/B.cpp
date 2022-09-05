#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, sz[maxn];
vector<int> ans, G[maxn];

int main() {
    scanf("%d", &n);
    if (!(n & 1)) puts("NO"), exit(0);
    for (int i = 1, p; i <= n; i++) {
        scanf("%d", &p);
        if (!p) continue;
        G[i].push_back(p), G[p].push_back(i);
    }
    function<void(int, int)> init = [&](int v, int fa) {
        sz[v] = 1;
        for (int u : G[v]) if (u ^ fa) {
            init(u, v), sz[v] += sz[u];
        }
    };
    function<void(int, int)> dfs = [&](int v, int fa) {
        for (int u : G[v]) if (u ^ fa) {
            if (!(sz[u] & 1)) dfs(u, v);
        }
        ans.push_back(v);
        for (int u : G[v]) if (u ^ fa) {
            if (sz[u] & 1) dfs(u, v);
        }
    };
    init(1, 0), dfs(1, 0);
    puts("YES");
    for (int x : ans) printf("%d\n", x);
    return 0;
}