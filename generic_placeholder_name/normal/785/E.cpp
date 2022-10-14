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
using ordered_set = tree<T, null_type, cmp, rb_tree_tag, tree_order_statistics_node_update>;
typedef trie<string, null_type, trie_string_access_traits<>, pat_trie_tag, trie_prefix_search_node_update>
pref_trie;

constexpr int N = 200005;
int a[N];

namespace fenw {
    ordered_set<int> t[N];

    int query(int x, int k) {
        int ans = 0;
        for(; x; x -= x & -x) ans += t[x].order_of_key(k);
        return ans;
    }

    void insert(int x, int k) {
        for(; x < N; x += x & -x) t[x].insert(k);
    }

    void erase(int x, int k) {
        for(; x < N; x += x & -x) t[x].erase(k);
    }
};

int32_t main() {
    fastio;
    ll inv = 0;
    int n, m; cin >> n >> m;
    rep1(i, n) a[i] = i, fenw::insert(i, i);
    while(m--) {
        int i, j; cin >> i >> j;
        if(i != j) {
            inv -= 2 * (fenw::query(j - 1, a[i]) - fenw::query(i, a[i]));
            inv += 2 * (fenw::query(j - 1, a[j]) - fenw::query(i, a[j]));
            inv += (a[i] < a[j] ? 1 : -1);
            fenw::erase(i, a[i]);
            fenw::erase(j, a[j]);
            swap(a[i], a[j]);
            fenw::insert(i, a[i]);
            fenw::insert(j, a[j]);
        }
        cout << inv << endl;
    }
}