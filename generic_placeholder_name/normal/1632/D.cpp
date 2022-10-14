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

void tr(vector<pii>& t, int id, int x) {
    t.eb(id, x);
    vector<pii> new_t;
    for(auto& [id, v]: t) {
        int new_v = gcd(v, x);
        if(new_t.empty() || new_v != new_t.back().se) new_t.eb(id, new_v);
    }
    t = move(new_t);
}

int32_t main() {
    fastio;
    int n; cin >> n;
    vi a(n); rep(i, n) cin >> a[i];
    vector<pii> pos;
    int now = 0, lst = 0;
    rep(i, n) {
        tr(pos, i, a[i]);
        for(int j = (int)pos.size() - 1; ~j; j--) {
            int l = pos[j].fi, v = pos[j].se, r;
            if(j + 1 < pos.size()) r = pos[j + 1].fi - 1;
            else r = i;
            if(i - v + 1 >= l && i - v + 1 <= r) {
                int p = i - v + 1;
                if(p >= lst) now++, lst = i + 1;
                break;
            }
        }
        cout << now << ' ';
    }
}