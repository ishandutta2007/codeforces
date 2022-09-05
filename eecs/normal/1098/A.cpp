#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010;
int n, p[maxn];
long long ans, s[maxn];
vector<int> G[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]), G[p[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &s[i]);
    }
    function<void(int)> dfs = [&](int v) {
        if (!~s[v]) {
            long long mn = LLONG_MAX;
            for (int u : G[v]) mn = min(mn, s[u] - s[p[v]]);
            if (G[v].empty()) mn = 0;
            s[v] = s[p[v]] + mn;
        }
        for (int u : G[v]) dfs(u);
    };
    dfs(1);
    for (int i = 1; i <= n; i++) {
        long long x = s[i] - s[p[i]];
        if (x < 0) puts("-1"), exit(0);
        ans += x;
    }
    printf("%lld\n", ans);
    return 0;
}