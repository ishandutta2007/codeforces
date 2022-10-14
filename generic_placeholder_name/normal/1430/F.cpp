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
template<typename _def> using ordered_set=tree<_def, null_type, greater<_def>, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update> pref_trie;

constexpr int N=2005;
ll l[N], r[N], a[N];
ll dp[N];

int32_t main() {
    fastio;
    int n; ll k; cin>>n>>k;
    rep(i, n) cin>>l[i]>>r[i]>>a[i];
    for(int i=n-1; ~i; i--) {
        ll need=a[i];
        if(r[i]==l[i+1]) need+=dp[i+1];
        if(k*(r[i]-l[i]+1)<need) return cout<<"-1\n", 0;
        dp[i]=max(0LL, need-1LL*(r[i]-l[i])*k);
    }
    ll ans=0, cur=k;
    rep(i, n) {
        if(cur<dp[i]) ans+=cur, cur=k;
        ans+=a[i];
        cur=((cur-a[i])%k+k)%k;
    }
    cout<<ans<<endl;
}