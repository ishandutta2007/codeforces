#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define fi first
#define se second
#define pb push_back
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

int m;
vi x[3]; vll pf[3];

void init() {
    int n; cin>>n>>m;
    rep(i, n) {
        int w, c; cin>>w>>c;
        x[--w].pb(c);
    }
    rep(i, 3) sort(all(x[i]), greater<int>());
    rep(i, 3) {
        pf[i].resize(x[i].size()+1, 0);
        rep1(j, pf[i].size()-1) pf[i][j]=pf[i][j-1]+x[i][j-1];
    }
}

ll __f(int x, int y) {return pf[1][y]+pf[0][min(int(pf[0].size()-1), m-3*x-2*y)];}

ll _f(int x) {
    int l=0, r=min((m-3*x)/2, int(pf[1].size()-1));
    while(r-l>3) {
        int m1=l+(r-l)/3, m2=r-(r-l)/3;
        if(__f(x, m1)<__f(x, m2)) l=m1;
        else r=m2;
    }
    ll ans=0;
    while(l<=r) ans=max(ans, __f(x, l++));
    return ans;
}

ll f() {
    int l=0, r=min(m/3, int(pf[2].size()-1));
    while(r-l>3) {
        int m1=l+(r-l)/3, m2=r-(r-l)/3;
        if(pf[2][m1]+_f(m1)<pf[2][m2]+_f(m2)) l=m1;
        else r=m2;
    }
    ll ans=0;
    while(l<=r) ans=max(ans, pf[2][l]+_f(l++));
    return ans;
}

void solve() {
    init(); cout<<f()<<endl;
}

int32_t main() {
    fastio; solve();
}