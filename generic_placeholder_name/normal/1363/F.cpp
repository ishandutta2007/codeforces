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

void solve(string& s, string& t) {
    int n=s.length();
    int ss[n+1][26], tt[n+1][26];
    memset(ss, 0, sizeof(ss)); memset(tt, 0, sizeof(tt));
    rep1(i, n) rep(j, 26) {
        ss[i][j]=ss[i-1][j]+(s[i-1]==j+'a');
        tt[i][j]=tt[i-1][j]+(t[i-1]==j+'a');
    }
    rep(i, 26) if(ss[n][i]!=tt[n][i]) {cout<<"-1\n"; return;}
    vvi dp(n+2, vi(n+2, -1));
    dp[0][0]=0;
    rep(i, n+1) rep(j, n+1) {
        dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
        dp[i][j+1]=max(dp[i][j+1], dp[i][j]);
        if(s[i]==t[j]) {
            bool chk=1;
            rep(k, 26) chk&=ss[i][k]<=tt[j][k];
            if(chk) dp[i+1][j+1]=max(dp[i+1][j+1], dp[i][j]+1);
        }
    }
    cout<<n-dp[n][n]<<endl;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        int n; cin>>n;
        string s, t; cin>>s>>t;
        solve(s, t);
    }
}