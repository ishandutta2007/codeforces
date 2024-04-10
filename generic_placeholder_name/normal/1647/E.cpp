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

constexpr int N = 1e5 + 5;
constexpr int K = 30;
int a[N], cnt[N], to[N][K + 1], f[N];

int32_t main() {
    fastio;
    int n; cin >> n;
    rep1(i, n) cin >> to[i][0], cnt[to[i][0]] = 1;
    rep1(i, n) cin >> a[i];
    int zeros = 0;
    rep1(i, n) zeros += (cnt[i] == 0);
    int iters = (*max_element(a + 1, a + 1 + n) - n) / zeros;
    rep1(j, K) rep1(i, n) to[i][j] = to[to[i][j - 1]][j - 1];
    iota(f + 1, f + 1 + n, 1);
    for(int e = 30; ~e; e--) if((iters >> e) & 1) {
        rep1(i, n) f[i] = to[f[i]][e];
    }
    set<int> p, q;
    rep1(i, n) p.insert(i);
    rep1(i, n) if(a[i] <= n) p.erase(a[i]), q.insert(a[i]);
    rep1(i, n) {
        if(q.find(a[f[i]]) != q.end()) {
            cout << a[f[i]] << ' ';
            q.erase(a[f[i]]);
        }
        else {
            int x = *p.upper_bound(a[f[i]]);
            cout << x << ' ';
            p.erase(x);
        }
    }
}