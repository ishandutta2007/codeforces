#include <bits/stdc++.h>

#define MN 351000

using namespace std;
typedef long long ll;

ll n, m, v, d, x, ans[MN], bit[MN];
vector<pair<ll, ll> > queries[MN];

vector<int> adj[MN];
int a, b, dist[MN];

void update(ll idx, ll delta) {
    idx = min(idx, MN - 1LL);
    for(; idx < MN; idx += (idx & -idx)) bit[idx] += delta;
}

ll query(int idx) {
    ll res = 0;
    for(; idx; idx -= (idx & -idx)) res += bit[idx];
    return res;
}

void solve(int no, int pai = -1) {
    for(pair<ll, ll> q : queries[no]) {
        ll dd = q.first + dist[no];
        update(dd + 1, q.second);
    }

    ans[no] = query(MN-1) - query(dist[no]);

    for(int v : adj[no]) {
        if(v == pai) continue;
        dist[v] = dist[no] + 1;
        solve(v, no);
    }

    for(pair<ll, ll> q : queries[no]) {
        ll dd = q.first + dist[no];
        update(dd + 1, -q.second);
    }
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    scanf("%lld", &m);
    for(int i = 0; i < m; i++) {
        scanf("%lld %lld %lld", &v, &d, &x);
        queries[v].emplace_back(d, x);
    }

    solve(1);

    for(int i = 1; i <= n; i++) {
        printf("%lld ", ans[i]);
    }

    return 0;
}