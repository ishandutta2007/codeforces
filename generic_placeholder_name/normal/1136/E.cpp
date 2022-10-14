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

constexpr int N=1e5+2;
ll a[N], k[N], pf[N];
ll t[N*4+4], lz[N*4+4];

void build(ll a[], int v=1, int l=1, int r=N) {
    if(l==r) t[v]=a[l];
    else {
        int m=(l+r)/2;
        build(a, v*2, l, m);
        build(a, v*2+1, m+1, r);
        t[v]=t[v*2]+t[v*2+1];
    }
}

void push(int v, int l, int r) {
    t[v]+=lz[v]*(r-l+1);
    if(l!=r) {
        lz[v*2]+=lz[v];
        lz[v*2+1]+=lz[v];
    }
    lz[v]=0;
}

void upd(int l, int r, ll val, int v=1, int tl=1, int tr=N) {
    if(tl>tr) return;
    push(v, tl, tr);
    if(l>tr||r<tl) return;
    if(l<=tl&&r>=tr) {
        lz[v]+=val;
        push(v, tl, tr);
    }
    else {
        int tm=(tl+tr)/2;
        upd(l, r, val, v*2, tl, tm);
        upd(l, r, val, v*2+1, tm+1, tr);
        t[v]=t[v*2]+t[v*2+1];
    }
}

ll get(int l, int r, int v=1, int tl=1, int tr=N) {
    if(tl>tr) return 0;
    push(v, tl, tr);
    if(l>tr||r<tl) return 0;
    if(l<=tl&&r>=tr) return t[v];
    else {
        int tm=(tl+tr)/2;
        return get(l, r, v*2, tl, tm)+get(l, r, v*2+1, tm+1, tr);
    }
}

set<pii> s;
void update(int pos, ll x) {
    auto it=--s.lower_bound({pos, N});
	if(it->fi<pos) s.emplace(it->fi, pos-1);
	int last=it->se;
	s.erase(it); //holy shit I can't believe I deleted a fucking pointer then attempted to use it
	ll val=get(pos, pos);
	while(1) {
		auto it=s.lower_bound({pos, N});
		if(it==s.end()) break;
		int l=it->fi, r=it->se;
		ll g=get(l, l);
		ll newVal=val+x+(pf[l-1]-pf[pos-1]);
		if(g>newVal) break;
		upd(l, r, newVal-x-g);
		last=r;
		s.erase(it);
	}
	s.insert({pos, last});
	upd(pos, last, x);
}

int32_t main() {
    fastio;
    int n; cin>>n;
    rep1(i, n) cin>>a[i]; build(a);
    rep1(i, n-1) cin>>k[i];
    rep1(i, n-1) pf[i]=pf[i-1]+k[i];
    rep1(i, n) s.emplace(i, i);
    int q; cin>>q; while(q--) {
        char c; cin>>c;
        if(c=='+') {
            int l; ll x; cin>>l>>x;
            update(l, x);
        }
        else {
            int l, r; cin>>l>>r;
            cout<<get(l, r)<<endl;
        }
    }
}