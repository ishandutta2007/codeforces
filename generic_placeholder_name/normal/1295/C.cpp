#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

#pragma 03

using namespace std;
using namespace __gnu_pbds;

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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define gcd __gcd
#define lcm(a, b) (a)*(b)/gcd((a), (b))
#define fastio ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int solve(string s, string t) {
    bool occ[26]={0};
    rep(i, s.length()) occ[s[i]-'a']=1;
    rep(i, t.length()) if(!occ[t[i]-'a']) return -1;
    set<int> a[26];
    int dp[s.length()][26];
    rep(i, s.length()) a[s[i]-'a'].insert(i);
    rep(i, s.length()) rep(j, 26) {
        auto it=a[j].lower_bound(i+1);
        if(it==a[j].end()) dp[i][j]=*a[j].begin();
        else dp[i][j]=*it;
    }
    int curr=-1, ans=1;
    rep(i, t.length()) {
        if(curr==-1) {
            if(s[0]==t[i]) curr=0;
            else curr=dp[0][t[i]-'a'];
        }
        else {
            if(dp[curr][t[i]-'a']<=curr) ans++;
            curr=dp[curr][t[i]-'a'];
        }
    }
    return ans;
}

int32_t main() {
    fastio;
    int q; cin>>q; while(q--) {
        string s, t; cin>>s>>t;
        cout<<solve(s, t)<<endl;
    }
}