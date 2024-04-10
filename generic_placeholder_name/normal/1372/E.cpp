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

constexpr int N=100;
int dp[N][N], l[N][N], r[N][N];
bool vis[N][N];
int n, m;

int get(int idx, int lf, int rg) {
    int ans=0;
    rep(i, n) ans+=(l[i][idx]>=lf&&r[i][idx]<=rg);
    return ans*ans;
}

int solve(int lf, int rg) {
    if(lf>rg) return 0;
    if(vis[lf][rg]) return dp[lf][rg];
    vis[lf][rg]=1;
    int ans=0;
    for(int k=lf; k<=rg; k++) ans=max(ans, solve(lf, k-1)+solve(k+1, rg)+get(k, lf, rg));
    return dp[lf][rg]=ans;
}

int32_t main() {
    fastio;
    cin>>n>>m;
    rep(i, n) {
        int t; cin>>t;
        rep(_, t) {
            int lf, rg; cin>>lf>>rg; --lf, --rg;
            for(int j=lf; j<=rg; j++) l[i][j]=lf, r[i][j]=rg;
        }
    }
    cout<<solve(0, m-1)<<endl;
}