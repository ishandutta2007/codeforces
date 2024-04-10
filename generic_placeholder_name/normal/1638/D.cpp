#pragma GCC optimize("Ofast")
#pragma GCC optimization("unroll-loops")
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

constexpr int N = 1005;
int a[N][N];
vector<tuple<int, int, int>> ans;
int n, m;

int color(int x, int y) {
    if(x <= 0 || x >= n || y <= 0 || y >= m) return 0;
    if(a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1] == 0) return 0;
    int c = 0;
    if(a[x][y] != 0) c = a[x][y];
    if(a[x][y + 1] != 0) c = a[x][y + 1];
    if(a[x + 1][y] != 0) c = a[x + 1][y];
    if(a[x + 1][y + 1] != 0) c = a[x + 1][y + 1];
    if(a[x][y] != 0 && a[x][y] != c) return 0;
    if(a[x][y + 1] != 0 && a[x][y + 1] != c) return 0;
    if(a[x + 1][y] != 0 && a[x + 1][y] != c) return 0;
    if(a[x + 1][y + 1] != 0 && a[x + 1][y + 1] != c) return 0;
    return c;
}

void dfs(int x, int y, int c) {
    ans.eb(x, y, c);
    rep(i, 2) rep(j, 2) a[x + i][y + j] = 0;
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            int c = color(x + i, y + j);
            if(c) dfs(x + i, y + j, c);
        }
    }
}

int32_t main() {
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int c = color(i, j);
            if(c) dfs(i, j, c);
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) return cout << "-1\n", 0;
        }
    }
    reverse(all(ans));
    cout << ans.size() << endl;
    for(auto& [x, y, c]: ans) cout << x << ' ' << y << ' ' << c << endl;
}