#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma,popcnt")

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

constexpr int N=1e5+1, M=1001;
int n, m;
bitset<M> t[4*N+4], PRIMES, EMPTY;
int lz[4*N+4], a[N], in[N], out[N];
vi adj[N];

void dfs(int u, int par=-1) {
    static int t=0;
    in[u]=t++;
    for(int v: adj[u]) if(v!=par) dfs(v, u);
    out[u]=t-1;
}

void calc_primes(int n) {
    vb isprime(m, 1);
    for(int i=2; i*i<m; i++) if(isprime[i]) {
        for(int j=i*i; j<m; j+=i) isprime[j]=0;
    }
    for(int i=2; i<m; i++) if(isprime[i]) PRIMES.set(i);
}

void init(int pos, int val, int v=1, int l=0, int r=n-1) {
    if(l==r) t[v].set(val);
    else {
        int m=(l+r)/2;
        if(pos<=m) init(pos, val, v*2, l, m);
        else init(pos, val, v*2+1, m+1, r);
        t[v]=t[v*2]|t[v*2+1];
    }
}

void push(int v) {
    if(!lz[v]) return;
    t[v*2]=(t[v*2]<<lz[v])|(t[v*2]>>(m-lz[v]));
    (lz[v*2]+=lz[v])%=m;
    t[v*2+1]=(t[v*2+1]<<lz[v])|(t[v*2+1]>>(m-lz[v]));
    (lz[v*2+1]+=lz[v])%=m;
    lz[v]=0;
}

void upd(int ql, int qr, int val, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v]=(t[v]<<val)|(t[v]>>(m-val));
        (lz[v]+=val)%=m;
    }
    else {
        push(v);
        int m=(l+r)/2;
        upd(ql, qr, val, v*2, l, m);
        upd(ql, qr, val, v*2+1, m+1, r);
        t[v]=t[v*2]|t[v*2+1];
    }
}

bitset<M> get(int ql, int qr, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return EMPTY;
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v);
        int m=(l+r)/2;
        return get(ql, qr, v*2, l, m)|get(ql, qr, v*2+1, m+1, r);
    }
}

int32_t main() {
    fastio;
    cin>>n>>m;
    calc_primes(m);
    rep(i, n) cin>>a[i], a[i]%=m;
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        adj[--u].pb(--v); adj[v].pb(u);
    }
    dfs(0);
    rep(i, n) init(in[i], a[i]);
    int q; cin>>q;
    while(q--) {
        int t; cin>>t;
        if(t==1) {
            int v, x; cin>>v>>x; --v; x%=m;
            upd(in[v], out[v], x);
        }
        else {
            int v; cin>>v; --v;
            auto it=get(in[v], out[v]);
            cout<<(get(in[v], out[v])&PRIMES).count()<<endl;
        }
    }
}