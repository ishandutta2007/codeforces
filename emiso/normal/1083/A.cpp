#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll n, a[MN], ans;
vector<pair<ll, ll>> adj[MN];

ll up[MN];

void dfs(int u, int pai = 0) {
    ll u1 = 0, u2 = 0;
    for (auto [v, c] : adj[u]) if (v != pai) {
        dfs(v, u);
        ll tmp = up[v] - c;
        if (tmp > u2) {
            u2 = tmp;
            if (u2 > u1) swap(u2, u1);
        }
    }
    assert(u1 >= u2);
    up[u] = u1 + a[u];
    ans = max(ans, up[u] + u2);
}

int main() {
    scanf("%lld", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        ans = max(ans, a[i]);
    }
    for (int i = 1, u, v, c; i < n; i++) {
        scanf("%d %d %d", &u, &v, &c);
        adj[u].emplace_back(v, c);
        adj[v].emplace_back(u, c);
    }
    dfs(1);
    printf("%lld\n", ans);
    return 0;
}