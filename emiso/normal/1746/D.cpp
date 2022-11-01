#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define MN 1001000

ll t = 1, n, k, a[MN], p[MN];
vector<int> adj[MN];

pair<ll, ll> solve(int u, int k) {
    int ch = adj[u].size();
    if (ch == 0) {
        return {a[u] * k, a[u]};
    }
    vector<ll> v;

    ll ans = a[u] * k;

    for (int c : adj[u]) {
        auto tt = solve(c, k / ch);
        v.push_back(tt.second);
        ans += tt.first;
    }

    sort(v.rbegin(), v.rend());
    int rem = k % ch;
    for (int i = 0; i < rem; i++)
        ans += v[i];

    return {ans, v[rem] + a[u]};
}

int main() {
    scanf("%lld", &t);
    st:
    scanf("%lld %lld", &n, &k);

    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }

    for(int i = 2; i <= n; i++) {
        scanf("%lld", &p[i]);
        adj[p[i]].push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }

    printf("%lld\n", solve(1, k).first);
    if(--t) goto st;
    return 0;
}