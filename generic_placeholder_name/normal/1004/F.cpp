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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//Note
//Complexity: I think O(n log n log MAX)

//there is also a divide and conquer solution
//although I don't really understand how to optimize the thing
//from O(n log^3) to n log^2
//and I am more comfortable with segtrees than totally exotic structs anyway

//enough about that

//Extra note:
//so if you squint really hard this does exactly the same thing as the other solution
//so ...
//well whatever

constexpr int N=1e5+2;
int a[N];
int n, x;

struct node {
    ll ans;
    int all;
    int l, r;
    vector<pii> pf, sf; //first is or sum, second is position
    node() {ans=all=l=r=0; pf.clear(), sf.clear();}
    node(int p, int v) {
        l=r=p;
        pf.eb(v, p), sf.eb(v, p);
        all=v; ans=v>=x;
    }
    friend node operator + (const node& a, const node& b) {
        node res;
        res.l=a.l; res.r=b.r;
        res.all=a.all|b.all;
        res.ans=a.ans+b.ans;
        res.pf=a.pf; res.sf=b.sf;
        for(const pii& it: b.pf) {
            const int v=it.fi, p=it.se;
            if((a.all|v)!=res.pf.back().fi) res.pf.eb(a.all|v, p);
        }
        for(const pii& it: a.sf) {
            const int v=it.fi, p=it.se;
            if((b.all|v)!=res.sf.back().fi) res.sf.eb(b.all|v, p);
        }
        int j=0;
        for(int i=b.pf.size()-1; i>=0; i--) {
            while(j<a.sf.size()&&(b.pf[i].fi|a.sf[j].fi)<x) j++;
            if (j<a.sf.size()) {
                const int u=(i<b.pf.size()-1?b.pf[i+1].se:b.r+1)-b.pf[i].se;
                const int v=a.sf[j].se-a.l+1;
                res.ans+=1LL*u*v;
            }
            else break;
        }
        return res;
    }
} t[4*N+4];

void build(int a[], int v=1, int l=1, int r=n) {
    if(l==r) t[v]=node(l, a[l]);
    else {
        int m=(l+r)/2;
        build(a, v*2, l, m);
        build(a, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void upd(int pos, int val, int v=1, int tl=1, int tr=n) {
    if(tl==tr) t[v]=node(pos, val);
    else {
        int tm=(tl+tr)/2;
        if(pos<=tm) upd(pos, val, v*2, tl, tm);
        else upd(pos, val, v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

node get(int l, int r, int v=1, int tl=1, int tr=n) {
    if(l==tl&&r==tr) return t[v];
    else {
        int tm=(tl+tr)/2;
        if(r<=tm) return get(l, r, v*2, tl, tm);
        else if(l>tm) return get(l, r, v*2+1, tm+1, tr);
        else return get(l, tm, v*2, tl, tm)+get(tm+1, r, v*2+1, tm+1, tr);
    }
}

int32_t main() {
    fastio;
    int m; cin>>n>>m>>x;
    rep1(i, n) cin>>a[i];
    build(a);
    while(m--) {
        int t; cin>>t;
        if(t==1) {
            int pos, val;
            cin>>pos>>val;
            upd(pos, val);
        }
        else {
            int l, r;
            cin>>l>>r;
            cout<<get(l, r).ans<<endl;
        }
    }
}