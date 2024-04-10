#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops, no-stack-protector")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

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
template<typename T, typename cmp = less<T>>
using ordered_set=tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=1005;
int dp[N][N][2];

constexpr int MOD=998244353;
void add(int& a, int b) {if((a+=b)>=MOD) a-=MOD;}

int32_t main() {
    fastio;
    string a, b; cin>>a>>b;
    int n=a.size(), m=b.size();
    a="#"+a; b="#"+b;
    rep1(i, n) {dp[i][0][0]=1; if(a[i]!=a[i-1]) add(dp[i][0][0], dp[i-1][0][0]);}
    rep1(i, m) {dp[0][i][1]=1; if(b[i]!=b[i-1]) add(dp[0][i][1], dp[0][i-1][1]);}
    int ans=0;
    rep1(i, n) {rep1(j, m) {
        if(a[i]!=b[j]) dp[i][j][0]=dp[0][j][1], dp[i][j][1]=dp[i][0][0];
        if(i>1&&a[i]!=a[i-1]) add(dp[i][j][0], dp[i-1][j][0]);
        if(i>1&&a[i]!=b[j]) add(dp[i][j][0], dp[i-1][j][1]);
        if(j>1&&b[j]!=b[j-1]) add(dp[i][j][1], dp[i][j-1][1]);
        if(j>1&&b[j]!=a[i]) add(dp[i][j][1], dp[i][j-1][0]);
        add(ans, dp[i][j][0]);
        add(ans, dp[i][j][1]);
    }cout<<endl;}
    cout<<ans<<endl;
}