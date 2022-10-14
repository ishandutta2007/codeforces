#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize ("Ofast")
#pragma GCC optimization ("unroll-loops, no-stack-protector")
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

constexpr int N=3e5+1;
int n, q;
int a[N], pf[N], vis[N];
vector<pii> Q[N];
int ans[N];

struct SegTree {
    array<int, 4*N+8> sum, mn, lz;
    inline void push(int v, int l, int r) {
        if(!lz[v]) return;
        int m=(l+r)/2;
        sum[v*2]+=lz[v]*(m-l+1);
        sum[v*2+1]+=lz[v]*(r-m);
        mn[v*2]+=lz[v];
        mn[v*2+1]+=lz[v];
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
        lz[v]=0;
    }
    inline void pull(int v) {
        sum[v]=sum[v*2]+sum[v*2+1];
        mn[v]=min(mn[v*2], mn[v*2+1]);
    }
    int bs(int val, int v=1, int l=0, int r=n) {
        if(l==r) return l;
        else {
            push(v, l, r);
            int m=(l+r)/2;
            if(mn[v*2]<val) return bs(val, v*2, l, m);
            else return bs(val, v*2+1, m+1, r);
        }
    }
    void upd(int ql, int qr, int val, int v=1, int l=0, int r=n) {
        if(ql>r||qr<l) return;
        if(ql<=l&&qr>=r) {
            sum[v]+=val*(r-l+1);
            mn[v]+=val;
            lz[v]+=val;
        }
        else {
            push(v, l, r);
            int m=(l+r)/2;
            upd(ql, qr, val, v*2, l, m);
            upd(ql, qr, val, v*2+1, m+1, r);
            pull(v);
        }
    }
    int get(int ql, int qr, int v=1, int l=0, int r=n) {
        if(ql>r||qr<l) return 0;
        if(ql<=l&&qr>=r) return sum[v];
        else {
            push(v, l, r);
            int m=(l+r)/2;
            return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
        }
    }
} t;

void add(int idx) {
    if(a[idx]<0) return;
    else if(a[idx]==0) t.upd(0, idx, 1);
    else t.upd(0, t.bs(a[idx])-1, 1);
}

int32_t main() {
    fastio;
    cin>>n>>q; rep(i, n) cin>>a[i], a[i]=i-a[i]+1;
    rep(i, q) {
        int x, y; cin>>x>>y;
        Q[n-y-1].eb(x, i);
    }
    rep(i, n) {
        if(i) pf[i]+=pf[i-1];
        if(a[i]>=0&&a[i]<=pf[i]) {
            vis[i]=1;
            if(i<n) pf[i+1]++;
        }
    }
    rep(i, n) {
        add(i);
        for(auto& x: Q[i]) ans[x.se]=t.get(x.fi, x.fi);
    }
    rep(i, q) cout<<ans[i]<<endl;
}