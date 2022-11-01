#include <bits/stdc++.h>

#define MN 100100
#define debug(args...) for(auto x : {args}) cerr << x << " "; cerr << endl;
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

ll n, ans, p[MN], d[MN], c[MN];
vector<ll> adj[MN];

void dfs(int node) {
    c[d[node]]++;
    for(ll v : adj[node]) {
        d[v] = d[node] + 1;
        dfs(v);
    }
}

int main() {
    scanf("%lld", &n);

    p[0] = 1;
    for(int i = 2; i <= n; i++) {
        scanf("%lld", &p[i]);
        adj[p[i]].push_back(i);
    }

    d[1] = 0;
    dfs(1);
    for(int i = 0; i < MN; i++) {
      ans += (c[i] % 2);
    }
    printf("%lld\n", ans);
    return 0;
}