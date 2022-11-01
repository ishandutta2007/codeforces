#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#ifdef EBUG
#include "trace.h"
#else
template<typename... Args> void trace(Args... args) {}
template<typename... Args> void recInit(Args... args) {}
template<typename... Args> void recEnd(Args... args) {}
#define trace2(args...) trace(args)
#endif

#define MN 1001000

ll t = 1, n;
vector<int> adj[MN];

pair<ll, ll> solve(int u, int pai = 0) {
    ll ret = 0, can = 0, nocap = 0;
    for(int v : adj[u]) {
        if(v == pai) continue;
        auto tt = solve(v, u);
        ret += tt.first - tt.second;
        nocap |= (tt.second == 0);
    }
    if(nocap) can = 1;
    else ret++;
    return {ret, can};
}


int main() {
    scanf("%lld", &t);
    st: 
    scanf("%lld", &n);

    for(int i = 1, a, b; i < n; i++) {
        scanf("%d %d", &a, &b);
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    printf("%lld\n", solve(1).first);
    for(int i = 0; i <= n; i++) {
        adj[i].clear();
    }

    if(--t) goto st;
    return 0;
}