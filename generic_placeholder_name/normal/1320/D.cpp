#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

constexpr ll MOD=1e9+123, p=31, q=13;
constexpr int N=2e5+2;
ll pw[N], h[N][2]; int cnt[N];

ll get(int l, int r, int par) {
    return (h[r][par]-h[l-1][par]*pw[cnt[r]-cnt[l-1]]%MOD+MOD)%MOD;
}

int32_t main() {
    fastio;
    int n; string s; cin>>n>>s; s="#"+s;
    pw[0]=1;
    rep1(i, n) {
        pw[i]=pw[i-1]*p%MOD;
        if(s[i]=='1') h[i][0]=h[i-1][0], h[i][1]=h[i-1][1], cnt[i]=cnt[i-1];
        else {
            h[i][0]=(h[i-1][0]*p+q+((i&1)^1))%MOD;
            h[i][1]=(h[i-1][1]*p+q+(i&1))%MOD;
            cnt[i]=cnt[i-1]+1;
        }
    }
    int t; cin>>t; while(t--) {
        int x, y, len; cin>>x>>y>>len;
        cout<<(get(x, x+len-1, x&1)==get(y, y+len-1, y&1)?"YES\n":"NO\n");
    }
}