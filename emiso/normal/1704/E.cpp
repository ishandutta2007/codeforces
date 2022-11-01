#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000
#define MOD 998244353

ll t = 1, n, m, ans, a[MN], deg[MN];
vector<ll> adj[MN], radj[MN];

int main() {
    scanf("%lld", &t);
    st: ans = 0;
    scanf("%lld %lld", &n, &m);

    for(int i = 1; i <= n; i++) {
        deg[i] = 0;
        adj[i].clear();
        radj[i].clear();
    }

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    for(int i = 0, u, v; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }

    ll it = 0;
    while (it <= n + 2) {
        ll mx = LLONG_MIN;
        queue<int> q;
        for(int i = 1; i <= n; i++) for (int v : radj[i]) deg[v]++;
        for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
        assert(q.size() == 1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            mx = max(mx, a[u]);
            
            for (int v : adj[u]) 
                if (a[u]) a[v]++;
            if (a[u]) a[u]--;

            for (int v : radj[u]) {
                deg[v]--;
                if (!deg[v]) q.push(v);
            }
        }
        if (mx == 0) break;
        it++;
    }

    queue<int> q;
    for(int i = 1; i <= n; i++) for (int v : adj[i]) deg[v]++;
    for (int i = 1; i <= n; i++) if (!deg[i]) q.push(i);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        ans = a[u];
        for (int v : adj[u]) {
            a[v] = (a[v] + a[u]) % MOD;
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }

    ans = (ans + it) % MOD;
    printf("%lld\n", ans);
    if(--t) goto st;
    return 0;
}