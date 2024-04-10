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

#define ts to_string
vector<string> ans;
gp_hash_table<ll, bool> vis;

constexpr ll INF=5e18;
void put_sum(ll a, ll b) {
    assert(vis[a]&&vis[b]);
    ll t=a+b;
    if(vis[t]) return;
    vis[t]=1;
    ans.pb(ts(a)+" + "+ts(b));
}

void put_xor(ll a, ll b) {
    assert(vis[a]&&vis[b]);
    ll t=a^b;
    if(vis[t]) return;
    vis[t]=1;
    ans.pb(ts(a)+" ^ "+ts(b));
}

ll get_mult(ll a, ll m) {
    if(m==1) return a;
    else {
        ll x=get_mult(a, m/2);
        put_sum(x, x); x*=2;
        if(m&1) put_sum(x, a), x+=a;
        return x;
    }
}

ll gcd_ext(ll a, ll b, ll& x, ll& y) {
    if(!a) {x=0, y=1; return b;}
    ll x1, y1;
    ll g=gcd_ext(b%a, a, x1, y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}

ll mod_inv(ll a, ll b) {
    ll x, y;
    ll g=gcd_ext(a, b, x, y);
    assert(g==1);
    return (x%b+b)%b;
}

int32_t main() {
    fastio;
    ll n; cin>>n; vis[n]=1;
    ll m=1<<(__lg(n));
    ll r=get_mult(n, m);
    put_xor(n, r);
    ll x=n, y=n^r;
    ll mx=mod_inv(x, y), my=(x*mx-1)/y;
    if(my&1) my+=x, mx+=y;
    ll big=get_mult(x, mx), small=get_mult(y, my);
    put_xor(big, small);
    cout<<ans.size()<<endl;
    for(auto& s: ans) cout<<s<<endl;
}