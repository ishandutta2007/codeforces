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

constexpr int N=1e5+1;
int n;
int a[N];
struct node {
    ll sum; int mx;
    node(): sum(0), mx(0) {}
    node(int x): sum(x), mx(x) {}
    friend node operator + (const node& a, const node& b){
        node res;
        res.sum=a.sum+b.sum;
        res.mx=max(a.mx, b.mx);
        return res;
    }
} t[4*N+4];

void build(int a[], int v=1, int l=0, int r=n-1) {
    if(l==r) t[v]=node(a[l]);
    else {
        int m=(l+r)/2;
        build(a, v*2, l, m);
        build(a, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void upd_set(int pos, int val, int v=1, int l=0, int r=n-1) {
    if(l==r) t[v]=node(val);
    else {
        int m=(l+r)/2;
        if(pos<=m) upd_set(pos, val, v*2, l, m);
        else upd_set(pos, val, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void upd_mod(int ql, int qr, int val, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l||t[v].mx<val) return;
    if(l==r) t[v]=node(t[v].sum%val);
    else {
        int m=(l+r)/2;
        upd_mod(ql, qr, val, v*2, l, m);
        upd_mod(ql, qr, val, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

ll get(int ql, int qr, int v=1, int l=0, int r=n-1) {
    if(ql>r||qr<l) return 0;
    if(ql<=l&&qr>=r) return t[v].sum;
    else {
        int m=(l+r)/2;
        return get(ql, qr, v*2, l, m)+get(ql, qr, v*2+1, m+1, r);
    }
}

int32_t main() {
	fastio;
	int m; cin>>n>>m;
	rep(i, n) cin>>a[i];
	build(a);
	while(m--) {
        int t; cin>>t;
        if(t==1) {
            int l, r; cin>>l>>r;
            cout<<get(l-1, r-1)<<endl;
        }
        else if(t==2) {
            int l, r, x; cin>>l>>r>>x;
            upd_mod(l-1, r-1, x);
        }
        else {
            int k, x; cin>>k>>x;
            upd_set(k-1, x);
        }
	}
}