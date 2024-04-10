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

ll dist_sq(const pii& a, const pii& b) {
    return (a.fi-b.fi)*1LL*(a.fi-b.fi)+(a.se-b.se)*1LL*(a.se-b.se);
}

int32_t main() {
    fastio;
    int n; cin>>n;
    vector<pii> a(n);
    rep(i, n) cin>>a[i].fi>>a[i].se;
    vi idx(n-1); iota(all(idx), 1);
    int cur=0;
    vi ans{cur};
    while(!idx.empty()) {
        int nxt=idx[0]; ll mx=dist_sq(a[cur], a[idx[0]]);
        rep1(i, idx.size()-1) {
            ll now=dist_sq(a[cur], a[idx[i]]);
            if(now>mx) mx=now, nxt=idx[i];
        }
        idx.erase(find(all(idx), nxt));
        cur=nxt;
        ans.pb(cur);
    }
    for(auto& v: ans) cout<<v+1<<' '; cout<<endl;
}