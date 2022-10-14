#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/rope>

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

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

int32_t main() {
    fastio;
    int n, q; cin >> n >> q;
    set<int> active;
    rep(i, n + 1) active.insert(i);
    vi m(n, INT_MAX);
    vi ans(n, -1);
    while(q--) {
        int t; cin >> t;
        if(t == 0) {
            int l, r, x; cin >> l >> r >> x; --l, --r;
            if(x == 1) {
                int v = *active.lower_bound(l);
                m[v] = min(m[v], r);
                if(m[v] < *active.upper_bound(v)) ans[v] = 1;
            }
            else {
                int nxt = *active.upper_bound(r);
                for(auto itr = active.lower_bound(l); *itr <= r;) {
                    if(nxt != n) m[nxt] = min(m[nxt], m[*itr]);
                    ans[*itr] = 0;
                    active.erase(itr);
                    itr = active.lower_bound(l);
                }
                if(nxt != n && m[nxt] < *active.upper_bound(nxt)) ans[nxt] = 1;
                if(*active.begin() < l) {
                    int prv = *prev(active.lower_bound(l));
                    if(m[prv] < *active.upper_bound(prv)) ans[prv] = 1;
                }
            }
        }
        else {
            int p; cin >> p; --p;
            if(ans[p] == -1) cout << "N/A\n";
            else if(ans[p] == 0) cout << "NO\n";
            else cout << "YES\n";
        }
    }
}