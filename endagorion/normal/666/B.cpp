#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

const int maxn = 3100;

vi e[maxn], re[maxn];
int dist[maxn][maxn], rdist[maxn][maxn];
vi ord[maxn], rord[maxn];

int n, m;

void bfs(int v, vi *e, int *dist, vi &ord) {
    forn(i, n) dist[i] = 1e8;
    dist[v] = 0;
    vi q;
    q.pb(v);
    forn(cur, q.size()) {
        int v = q[cur];
        ord.pb(v);
        for (int u: e[v]) {
            if (dist[u] < 1e7) continue;
            dist[u] = dist[v] + 1;
            q.pb(u);
        }
    }
    reverse(all(ord));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> n >> m;
    forn(i, m) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        re[y].pb(x);
    }
    forn(i, n) bfs(i, e, dist[i], ord[i]);
    forn(i, n) bfs(i, re, rdist[i], rord[i]);
    int bsum = 0;
    tuple<int, int, int, int> ans;
    forn(i, n) forn(j, n) {
        if (i == j || dist[i][j] > 1e7) continue;
        forn(k, 3) {
            if (k >= rord[i].size()) continue;
            int h = rord[i][k];
            if (h == i || h == j || dist[h][i] > 1e7) continue;
            forn(l, 3) {
                if (l >= ord[j].size()) continue;
                int q = ord[j][l];             
                if (q == h || q == i || q == j || dist[j][q] > 1e7) continue;
                int sum = dist[h][i] + dist[i][j] + dist[j][q];
                if (uax(bsum, sum)) ans = mt(h, i, j, q);
            }
        }
    }
    int a, b, c, d;
    tie(a, b, c, d) = ans;
    cerr << bsum << '\n';
    cout << a + 1 << ' ' << b + 1 << ' ' << c + 1 << ' ' << d + 1 << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}