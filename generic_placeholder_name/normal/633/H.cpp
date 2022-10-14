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

//It's kinda funny
//How really hard problems tend to have really easy bypasses
//The limits are WAY too low anyway
//10000*10000 can comfortably fit in 0.5s
//so 30000*30000 in 5s is like
//reasonable
//expected even

//Let's see how far down we can take this, shall we?
//Two more opts added: more cache-friendly structs, int->short
//as I said, VERY poor TL proofing

constexpr int N=30001;
pair<int, short> a[N];
short f[N];
struct query{
    int last=-1; short l, r, c=0, ans=0;
} Q[N];
short n, m, q;

int32_t main() {
    fastio;
    cin>>n>>m;
    f[1]=f[2]=1; for(int i=3; i<=n; i++) f[i]=((int)f[i-1]+f[i-2])%m;
	rep(i, n) cin>>a[i].fi, a[i].se=i+1;
	sort(a, a+n);
	cin>>q; rep(i, q) cin>>Q[i].l>>Q[i].r;
	rep(i, n) {
	    const short t=a[i].fi%m;
	    #pragma GCC ivdep
	    rep(j, q) {
	        if(a[i].se>=Q[j].l&&a[i].se<=Q[j].r&&a[i].fi!=Q[j].last) Q[j].last=a[i].fi, Q[j].ans=((int)Q[j].ans+(int)f[++Q[j].c]*t)%m;
	    }
	}
	rep(i, q) cout<<Q[i].ans<<endl;
}