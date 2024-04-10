#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

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
constexpr ll INF=1e18;
int A[N], B[N];
int tin[N], tout[N];
vi adj[N];
int n, q;

void dfs(int u, int p=-1) {
    static int t=0;
    tin[u]=t++;
    if(p!=-1) A[u]+=A[p], B[u]+=B[p];
    for(int v: adj[u]) if(v!=p) dfs(v, u);
    tout[u]=t-1;
}

struct KineticTournament { //yes it's a segtree
    array<ll, 4*N+4> a, b, lz, rem; //rem = remaining time until a change happens
    inline void push(int v) {
        a[v*2]+=lz[v];
        a[v*2+1]+=lz[v];
        rem[v*2]-=lz[v];
        rem[v*2+1]-=lz[v];
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
        lz[v]=0;
    }
    inline void pull(int v) {
        if(a[v*2]*b[v*2]>a[v*2+1]*b[v*2+1]) {
            a[v]=a[v*2];
            b[v]=b[v*2];
        }
        else {
            a[v]=a[v*2+1];
            b[v]=b[v*2+1];
        }
        rem[v]=min(rem[v*2], rem[v*2+1]);
        if(b[v*2]!=b[v*2+1]){
            ll wait=(a[v*2+1]*b[v*2+1]-a[v*2]*b[v*2])/(b[v*2]-b[v*2+1]);
            if(wait>=0) rem[v]=min(rem[v], wait);
        }
    }
    void bld(int c=1, int v=1, int l=0, int r=n-1) {
        if(l==r) {
            a[v]=A[l];
            b[v]=c*B[l];
            rem[v]=INF;
            lz[v]=0;
        }
        else {
            int m=(l+r)/2;
            bld(c, v*2, l, m);
            bld(c, v*2+1, m+1, r);
            pull(v);
        }
    }
    void upd(int ql, int qr, int val, int v=1, int l=0, int r=n-1) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r&&rem[v]>=val) {
            a[v]+=val;
            rem[v]-=val;
            lz[v]+=val;
        }
        else {
            push(v);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            pull(v);
        }
    }
    ll get(int ql, int qr, int v=1, int l=0, int r=n-1) {
        if(ql>r||qr<l) return -INF;
        if(ql<=l&&qr>=r) return a[v]*b[v];
        else {
            push(v);
            int m=(l+r)/2;
            return max(get(ql, qr, v*2, l, m), get(ql, qr, v*2+1, m+1, r));
        }
    }
} POS, NEG;

int32_t main() {
    fastio;
    cin>>n>>q;
    rep1(v, n-1) {
        int u; cin>>u;
        adj[--u].pb(v);
    }
    rep(i, n) cin>>A[i]; rep(i, n) cin>>B[i];
    dfs(0);
    vi tmpA(n), tmpB(n);
    rep(i, n) tmpA[tin[i]]=A[i]; rep(i, n) A[i]=tmpA[i];
    rep(i, n) tmpB[tin[i]]=B[i]; rep(i, n) B[i]=tmpB[i];
    POS.bld(); NEG.bld(-1);
    rep(i, q) {
        int t; cin>>t;
        if(t==1) {
            int v, x; cin>>v>>x; --v;
            POS.upd(tin[v], tout[v], x);
            NEG.upd(tin[v], tout[v], x);
        }
        else {
            int v; cin>>v; --v;
            cout<<max(POS.get(tin[v], tout[v]), NEG.get(tin[v], tout[v]))<<endl;
        }
    }
}