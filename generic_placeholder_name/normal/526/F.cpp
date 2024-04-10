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
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

//3000 problem: exists
//Chinese magic DS guys:

constexpr int N=3e5+2;
constexpr int INF=1e9+7;

struct node {
    int mn, cnt, lz;
    node(int x=INF): mn(x), cnt(1), lz(0) {}
    friend node operator + (const node& a, const node& b) {
        node c;
        if(a.mn<b.mn) c.mn=a.mn, c.cnt=a.cnt;
        else if(b.mn<a.mn) c.mn=b.mn, c.cnt=b.cnt;
        else c.mn=a.mn, c.cnt=a.cnt+b.cnt;
        return c;
    }
} t[4*N+4];

int a[N];
int n;

void build(int v=1, int l=0, int r=n-1) {
    if(l==r) t[v]=node(0);
    else {
        int m=(l+r)/2;
        build(v*2, l, m);
        build(v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void push(int v) {
    #define l v*2
    #define r v*2+1
    t[l].mn+=t[v].lz;
    t[l].lz+=t[v].lz;
    t[r].mn+=t[v].lz;
    t[r].lz+=t[v].lz;
    t[v].lz=0;
    #undef l
    #undef r
}

void upd(int ql, int qr, int val, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return;
    if(ql<=l&&qr>=r) {
        t[v].mn+=val;
        t[v].lz+=val;
    }
    else {
        push(v);
        int m=(l+r)/2;
        upd(ql, qr, val, v*2, l, m);
        upd(ql, qr, val, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

node get(int ql, int qr, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return node();
    if(ql<=l&&qr>=r) return t[v];
    else {
        push(v);
        int m=(l+r)/2;
        return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
    }
}

int query(int l, int r) {
    node x=get(l, r);
    return x.mn?0:x.cnt;
}

int32_t main() {
    fastio;
    cin>>n;
    rep(i, n) {int x, y; cin>>x>>y; a[x-1]=y;}
    build();
    vi mx{-1}, mn{-1};
    ll ans=0;
    rep(i, n) {
        while(mx.back()!=-1&&a[mx.back()]<a[i]){
			int tmp=mx.back();
			mx.pop_back();
            upd(mx.back()+1, tmp, a[i]-a[tmp]);
		}
        mx.pb(i);
        while(mn.back()!=-1&&a[mn.back()]>a[i]){
			int tmp=mn.back();
			mn.pop_back();
            upd(mn.back()+1, tmp, a[tmp]-a[i]);
		}
        mn.pb(i);
        ans+=query(0, i);
        upd(0, i, -1);
    }
    cout<<ans<<endl;
}