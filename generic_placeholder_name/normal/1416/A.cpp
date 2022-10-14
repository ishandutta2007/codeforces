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
    int t; cin>>t;
    while(t--) {
        int n; cin>>n;
        gp_hash_table<int, int> mx, lst;
        rep1(i, n) {
            int x; cin>>x;
            mx[x]=max(mx[x], i-lst[x]);
            lst[x]=i;
        }
        for(auto& it: mx) mx[it.fi]=max(mx[it.fi], n+1-lst[it.fi]);
        vi ans(n+1, INT_MAX);
        for(auto& it: mx) ans[it.se]=min(ans[it.se], it.fi);
        for(int i=2; i<=n; i++) ans[i]=min(ans[i], ans[i-1]);
        rep1(i, n) cout<<(ans[i]==INT_MAX?-1:ans[i])<<' '; cout<<endl;
    }
}