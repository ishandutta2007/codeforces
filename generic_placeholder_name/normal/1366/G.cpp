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

int32_t main() {
    fastio;
    string s, t; cin>>s>>t;
    int n=s.length(), m=t.length();
    constexpr int INF=5e8;
    vvi dp(n+1, vi(m+1, INF));
    dp[0][0]=0;
    rep(i, n) {
        if(s[i]=='.') {
            rep(j, m+1) {
                if(dp[i][j]==INF) continue;
                dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
                if(j) dp[i+1][j-1]=min(dp[i+1][j-1], dp[i][j]);
            }
        }
        else {
            int f=i, w=1;
            while(f<n) {f++; w+=s[f]=='.'?-1:1; if(w==0) break;}
            rep(j, m+1) {
                if(dp[i][j]==INF) continue;
                dp[i+1][j]=min(dp[i+1][j], dp[i][j]+1);
                if(f<n) dp[f+1][j]=min(dp[f+1][j], dp[i][j]);
                if(j<m&&t[j]==s[i]) dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]);
            }
        }
    }
    cout<<dp[n][m]<<endl;
}