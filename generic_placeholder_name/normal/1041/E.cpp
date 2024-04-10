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
    fastio;
    //quick detour to 1900-land
    //they couldn't even be bothered to make it 1e5
    int n; cin>>n;
    vi a(n-1), ans;
    vb vis(n+1, 0);
    rep(i, n-1) {
        int u, v; cin>>u>>v;
        if(max(u, v)!=n) return cout<<"NO\n", 0;
        a[i]=min(u, v);
    }
    sort(all(a));
    rep(i, n-1) {
        while(vis[a[i]]) a[i]--;
        if(!a[i]) return cout<<"NO\n", 0;
        ans.pb(a[i]); vis[a[i]]=1;
    }
    ans.pb(n);
    cout<<"YES\n";
    rep(i, ans.size()-1) cout<<ans[i]<<' '<<ans[i+1]<<endl;
}