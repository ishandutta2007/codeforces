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

//1. why is the server so slow?
//2. why do I have such silly bugs?

constexpr int N = 2e3 + 5;
constexpr ll INF = 1e18;

constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, -1, 0, 1};

bool in(int x, int lim) {return 0 <= x && x < lim;}

ll dista[N][N], distb[N][N], a[N][N];
bool visa[N][N], visb[N][N];

int32_t main() {
    fastio;
    int n, m, w; cin >> n >> m >> w;
    rep(i, n) rep(j, m) {
        cin >> a[i][j];
        if(!~a[i][j]) visa[i][j] = visb[i][j] = 1;
        if(a[i][j] < 1) a[i][j] = INF;
    }
    rep(i, n) rep(j, m) dista[i][j] = INF;
    dista[0][0] = 0;
    visa[0][0] = 1;
    queue<pii> qa; qa.emplace(0, 0);
    while(!qa.empty()) {
        auto [x, y] = qa.front(); qa.pop();
        rep(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if(in(nx, n) && in(ny, m) && !visa[nx][ny]) {
                dista[nx][ny] = dista[x][y] + w;
                visa[nx][ny] = 1;
                qa.emplace(nx, ny);
            }
        }
    }
    rep(i, n) rep(j, m) distb[i][j] = INF;
    distb[n - 1][m - 1] = 0;
    visb[n - 1][m - 1] = 1;
    queue<pii> qb; qb.emplace(n - 1, m - 1);
    while(!qb.empty()) {
        auto [x, y] = qb.front(); qb.pop();
        rep(i, 4) {
            int nx = x + dx[i], ny = y + dy[i];
            if(in(nx, n) && in(ny, m) && !visb[nx][ny]) {
                distb[nx][ny] = distb[x][y] + w;
                visb[nx][ny] = 1;
                qb.emplace(nx, ny);
            }
        }
    }
    ll mina = INF, minb = INF;
    rep(i, n) rep(j, m) {
        mina = min(mina, dista[i][j] + a[i][j]);
        minb = min(minb, distb[i][j] + a[i][j]);
    } 
    ll ans = min(mina + minb, distb[0][0]);
    cout << (ans == INF ? -1 : ans) << endl;
}