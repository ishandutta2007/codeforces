#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

#define int int16_t
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
template<typename T, typename comp = less<T>>
using ordered_set = tree<T, null_type, comp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=3005;
int a[N];
int dp[N][N];
int pf[N][N]; //prefix reach i
int sf[N][N]; //suffix of dp[i][j -> n]

int32_t main() {
    fastio;
    int T; cin>>T;
    while(T--) {
        int n; cin>>n;
        rep1(i, n) cin>>a[i];
        rep(i, n+2) rep(j, n+2) dp[i][j]=N;
        rep(i, n+2) rep(j, n+2) pf[i][j]=0;
        rep(i, n+2) rep(j, n+2) sf[i][j]=N;
        rep1(i, n) rep1(j, i-1) pf[i][j]=pf[i][j-1]+(j+a[j]>=i);
        dp[n][n+1]=sf[n][n+1]=0;
        for(int l=n; l; l--) {
            for(int r=l+a[l]; r>l; r--) {
                int pre=pf[r][r-1]-pf[r][l];
                int suf=sf[r][l+a[l]+1];
                dp[l][r]=pre+suf;
                sf[l][r]=min(sf[l][r+1], dp[l][r]);
            }
        }
        int ans=N;
        rep1(i, n) ans=min(ans, dp[1][i]);
        cout<<ans<<endl;
    }
}