#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
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

const int maxn = 2100;
i64 dist[maxn][maxn];
i64 d2[maxn];

bool comp(pii p, pii q) {
    return dist[p.fi][p.se] < dist[q.fi][q.se];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n;
    cin >> n;
    i64 mx = 2e9;
    forn(i, n - 1) for1(j, n - i - 1) {
        cin >> dist[i][i + j];
        uin(mx, dist[i][i + j]);
        dist[i + j][i] = dist[i][i + j];
    }

    forn(i, n) d2[i] = 1e18;
    forn(i, n) forn(j, n) {
        if (i == j) continue;
        dist[i][j] -= mx;
//        if (!dist[i][j]) d2[i] = d2[j] = 0;
    }

    forn(i, n) forn(j, n) {
        if (i == j) continue;
        uin(d2[i], 2 * dist[i][j]);
    }

    vector<pii> p;
    forn(i, n) forn(j, i) p.pb(mp(j, i));
    sort(all(p), comp);

    for (auto w: p) {
        int x = w.fi, y = w.se;
        uin(d2[x], d2[y] + dist[x][y]);
        uin(d2[y], d2[x] + dist[x][y]);
    }

    forn(i, n) cout << d2[i] + 1LL * (n - 1) * mx << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}