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
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vvi pos(n + 1);
        rep(i, n) {
            int x; cin >> x;
            pos[x].eb(i);
        }
        rep(i, n + 1) reverse(all(pos[i]));
        vi ans;
        int ptr = -1;
        while(ptr + 1 < n) {
            int nxt = -1, idx = 0;
            for(int i = 0; i <= n; i++) {
                while(!pos[i].empty() && pos[i].back() <= ptr) pos[i].pop_back();
                if(pos[i].empty()) {idx = i; break;}
                else nxt = max(nxt, pos[i].back());
            }
            if(idx) {
                ans.pb(idx);
                ptr = nxt;
            }
            else break;
        }
        for(int i = 1; i <= n; i++) {
            while(!pos[i].empty() && pos[i].back() <= ptr) pos[i].pop_back();
            rep(_, pos[i].size()) ans.eb(0);
        }
        cout << ans.size() << endl;
        for(int x: ans) cout << x << ' '; cout << endl;
    }
}