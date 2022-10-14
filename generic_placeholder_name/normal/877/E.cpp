#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma 03

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define gcd __gcd
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define rep1(i, n) for (int i=1; i<=(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vll;
typedef vector<vector<ll>> vvll;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
template<typename _def> using ordered_set=tree<_def, null_type, less<_def>, rb_tree_tag, tree_order_statistics_node_update>;

constexpr int N=2e5+1;
int l[N], r[N];
vi adj[N];
int t[4*N+4];
bool lz[4*N+4];

void push(int v, int l, int r) {
    if(!lz[v]) return;
    int m=(l+r)/2;
    t[v*2]=(m-l+1)-t[v*2];
    lz[v*2]^=1;
    t[v*2+1]=(r-m)-t[v*2+1];
    lz[v*2+1]^=1;
    lz[v]=0;
}

void upd(int ql, int qr, int v=1, int l=0, int r=N) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v]=(r-l+1)-t[v];
        lz[v]^=1;
    }
    else {
        push(v, l, r);
        int m=(l+r)/2;
        upd(ql, qr, v*2, l, m);
        upd(ql, qr, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

int get(int ql, int qr, int v=1, int l=0, int r=N) {
    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v, l, r);
        int m=(l+r)/2;
        return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
    }
}

void dfs(int u, int par=-1) {
    static int t=0;
    l[u]=t++;
    for(int v: adj[u]) if(v!=par) dfs(v, u);
    r[u]=t-1;
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(u, n-1) {
        int v; cin>>v; --v;
        adj[u].pb(v); adj[v].pb(u);
    }
    dfs(0);
    rep(i, n) {int x; cin>>x; if(x) upd(l[i], l[i]);}
    int m; cin>>m;
    rep(i, m) {
        string t; int v; cin>>t>>v; --v;
        if(t=="pow") upd(l[v], r[v]);
        else cout<<get(l[v], r[v])<<endl;
    }
}