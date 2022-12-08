#include <iostream>
#include <cstdio>

#include <vector>

using namespace std;

typedef long long ll;
#define tll(x) static_cast<ll>(x)

typedef vector<int> vi;
#define pb push_back

const int MAXN = 3e5 + 100;

int N, M;

vi adj[MAXN];

struct Q {
    int d;
    ll v;
};
typedef vector<Q> vq;

vq q[MAXN];
ll ans[MAXN], mars[MAXN];

void solve(const int& n = 1, const int& p = -1, const int& d = 0, ll v = 0) {
    for(int i = 0, fd;i < q[n].size();i++) {
        mars[d] += q[n][i].v;
        if((fd = d + q[n][i].d + 1) <= N) mars[fd] -= q[n][i].v;
    }
    ans[n] = (v += mars[d]);
    for(int i = 0;i < adj[n].size();i++) if(adj[n][i] != p) solve(adj[n][i], n, d + 1, v);
    for(int i = 0, fd;i < q[n].size();i++) {
        mars[d] -= q[n][i].v;
        if((fd = d + q[n][i].d + 1) <= N) mars[fd] += q[n][i].v;
    }
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i <= N;i++) mars[i] = 0;
    for(int i = 0, u, v;i < N - 1;i++) {
        scanf("%d%d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    scanf("%d", &M);
    for(int i = 0, n, d, v;i < M;i++) {
        scanf("%d%d%d", &n, &d, &v);
        q[n].pb({d, tll(v)});
    }
    solve();
    for(int i = 1;i <= N;i++) printf("%lld ", ans[i]);
    printf("\n");
    return 0;
}