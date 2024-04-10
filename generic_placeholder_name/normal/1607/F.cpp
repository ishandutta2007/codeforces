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

constexpr int N = 2048;
bool vis[N][N];
bool in[N][N];
char c[N][N];
int w[N][N];
int n, m;

bool chk(int x, int y) {return 0 <= x && x < n && 0 <= y && y < m;}

vector<pii> st;
void go(int x, int y) {
    start: vis[x][y] = in[x][y] = 1;
    st.eb(x, y);
    int nx = x, ny = y;
    if(c[x][y] == 'L') ny--;
    if(c[x][y] == 'R') ny++;
    if(c[x][y] == 'U') nx--;
    if(c[x][y] == 'D') nx++;
    if(!chk(nx, ny)) {
        w[x][y] = 1;
        for(auto [x, y]: st) in[x][y] = 0;
        st.clear();
        return;
    }
    if(vis[nx][ny]) {
        if(!in[nx][ny]) {
            for(auto [x, y]: st) in[x][y] = 0;
            st.clear();
            return;
        }
        else {
            int v = find(rall(st), mp(nx, ny)) - st.rbegin() + 1;
            while(st.back() != mp(nx, ny)) {
                auto [x, y] = st.back();
                st.pop_back();
                in[x][y] = 0;
                w[x][y] = v;
            }
            auto [x, y] = st.back();
            st.pop_back();
            in[x][y] = 0;
            w[x][y] = v;
            while(!st.empty()) {
                auto [x, y] = st.back();
                st.pop_back();
                in[x][y] = 0;
            }
        }
    }
    else {
        x = nx, y = ny;
        goto start;
    }
}

void go2(int x, int y) {
    st.clear();
    start: st.eb(x, y);
    int nx = x, ny = y;
    if(c[x][y] == 'L') ny--;
    if(c[x][y] == 'R') ny++;
    if(c[x][y] == 'U') nx--;
    if(c[x][y] == 'D') nx++;
    if(!~w[nx][ny]) {
        x = nx, y = ny;
        goto start;
    }
    else {
        w[x][y] = w[nx][ny] + 1;
        st.pop_back();
        while(!st.empty()) {
            auto& [nx, ny] = st.back();
            st.pop_back();
            w[nx][ny] = w[x][y] + 1;
            x = nx, y = ny;
        }
    }
}

int32_t main() {
    fastio;
    int T; cin >> T;
    while(T--) {
        cin >> n >> m;
        rep(i, n) rep(j, m) cin >> c[i][j];
        rep(i, n) rep(j, m) in[i][j] = vis[i][j] = 0, w[i][j] = -1;
        rep(i, n) rep(j, m) if(!vis[i][j]) go(i, j);
        rep(i, n) rep(j, m) if(!~w[i][j]) go2(i, j);
        tuple<int, int, int> ans = {0, 0, 0};
        rep(i, n) rep(j, m) ans = max(ans, make_tuple(w[i][j], i, j));
        auto [v, x, y] = ans;
        cout << x + 1 << ' ' << y + 1 << ' ' << v << endl;
    }
}