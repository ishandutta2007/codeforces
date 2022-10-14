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

constexpr int N = 2e5 + 5;
int t[N << 2];

void ask(int v, int l, int r) {
    if(~t[v]) return;
    cout << "? " << l << ' ' << r << endl;
    cin >> t[v];
    t[v] = (r - l + 1) - t[v];
}

int dfs(int v, int l, int r, int val) {
    if(l == r) return --t[v], l;
    else {
        int m = (l + r) / 2;
        ask(v * 2, l, m);
        t[v * 2 + 1] = t[v] - t[v * 2];
        --t[v];
        if(t[v * 2] >= val) return dfs(v * 2, l, m, val);
        else return dfs(v * 2 + 1, m + 1, r, val - t[v * 2]);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    int n, T; cin >> n >> T;
    memset(t, -1, sizeof(t));
    rep(i, T) {
        int x; cin >> x;
        if(!i) ask(1, 1, n);
        int ans = dfs(1, 1, n, x);
        cout << "! " << ans << endl;
    }
}