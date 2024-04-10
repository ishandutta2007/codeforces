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

constexpr int N = 3e5 + 5;
vi adj_a[N], adj_b[N];
int t[1 << 20];
int n;

void upd(int ql, int qr, int val, int v = 1, int l = 0, int r = n - 1) {
    if(ql > r || qr < l) return;
    if(ql <= l && qr >= r) t[v] += val;
    else {
        int m = (l + r) / 2;
        upd(ql, qr, val, v * 2, l, m);
        upd(ql, qr, val, v * 2 + 1, m + 1, r);
    }
}

int query(int pos, int v = 1, int l = 0, int r = n - 1) {
    if(l == r) return t[v];
    else {
        int m = (l + r) / 2;
        if(pos <= m) return t[v] + query(pos, v * 2, l, m);
        else return t[v] + query(pos, v * 2 + 1, m + 1, r);
    }
}

int tt = 0;
int tin[N], tout[N];
void dfs_b(int u) {
    tin[u] = tt++;
    for(int v: adj_b[u]) dfs_b(v);
    tout[u] = tt - 1;
}

int ans, cur;
void dfs_a(int u) {
    int p = query(tin[u]);
    if(p) upd(tin[p - 1], tout[p - 1], -p);
    else cur++;
    upd(tin[u], tout[u], u + 1);
    ans = max(ans, cur);
    for(int v: adj_a[u]) dfs_a(v);
    if(p) upd(tin[p - 1], tout[p - 1], p);
    else cur--;
    upd(tin[u], tout[u], - u - 1);
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        cin >> n;
        tt = ans = cur = 0;
        rep(i, n) adj_a[i].clear(), adj_b[i].clear();
        rep1(i, n - 1) {
            int p; cin >> p; --p;
            adj_a[p].pb(i);
        }
        rep1(i, n - 1) {
            int p; cin >> p; --p;
            adj_b[p].pb(i);
        }
        dfs_b(0);
        dfs_a(0);
        cout << ans << endl;
    }
}