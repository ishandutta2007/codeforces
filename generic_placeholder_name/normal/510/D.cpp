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

int32_t main() {
    int n; cin>>n;
    int a[n], b[n]; rep(i, n) cin>>a[i]; rep(i, n) cin>>b[i];
    const auto reduce=[](int a)->int {
        int x=1;
        for(int i=2; i*i<=a; i++) if(a%i==0) {
            x*=i;
            while(a%i==0) a/=i;
        }
        return x*a;
    };
    rep(i, n) a[i]=reduce(a[i]);
    int whole=0; rep(i, n) whole=gcd(whole, a[i]);
    if(whole!=1) return cout<<"-1\n", 0;
    map<int, int> dp[n];
    rep(i, n) {
        dp[i][a[i]]=b[i];
        rep(j, n) if(j!=i) {
            for(auto it: dp[i]) {
                int nx=gcd(it.fi, a[j]), nv=it.se+b[j];
                if(dp[i].find(nx)==dp[i].end()||nv<dp[i][nx]) dp[i][nx]=nv;
            }
        }
    }
    int ans=INT_MAX;
    rep(i, n) if(dp[i].find(1)!=dp[i].end()) ans=min(ans, dp[i][1]);
    cout<<ans<<endl;
}