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

constexpr int dx[] = {1, -1, 0, 0};
constexpr int dy[] = {0, 0, -1, 1};

vector<string> mat;
vector<vector<bool>> vis;
int n, m;

bool in(int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;}
int neighbors(int x, int y) {
    int ans = 0;
    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if(in(nx, ny) && !vis[nx][ny]) ans++;
    }
    return ans;
}

void dfs(int x, int y) {
    vis[x][y] = 1;
    rep(i, 4) {
        int nx = x + dx[i], ny = y + dy[i];
        if(in(nx, ny) && !vis[nx][ny] && neighbors(nx, ny) <= 1) dfs(nx, ny);
    }
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        cin >> n >> m;
        mat.resize(n);
        vis.assign(n, vector<bool>(m));
        rep(i, n) cin >> mat[i];
        int lx, ly;
        rep(i, n) rep(j, m) {
            if(mat[i][j] == '#') vis[i][j] = 1;
            if(mat[i][j] == 'L') lx = i, ly = j;
        }
        dfs(lx, ly);
        rep(i, n) {
            rep(j, m) {
                if(mat[i][j] != '.') cout << mat[i][j];
                else if(vis[i][j]) cout << '+';
                else cout << '.';
            }
            cout << endl;
        }
    }
}