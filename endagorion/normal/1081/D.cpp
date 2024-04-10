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

const int maxn = 110000;
int par[maxn], sz[maxn];

int root(int x) {
    return x == par[x] ? x : par[x] = root(par[x]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m, k;
    cin >> n >> m >> k;
    forn(i, n) par[i] = i;
    forn(i, k) {
        int x;
        cin >> x;
        sz[--x] = 1;
    }

    vector< tuple<int, int, int> > e(m);
    forn(i, m) {
        int x, y, w;
        cin >> x >> y >> w;
        --x; --y;
        e[i] = mt(w, x, y);
    }
    sort(all(e));

    for (auto ww: e) {
        int w, x, y;
        tie(w, x, y) = ww;
        x = root(x); y = root(y);
        if (x == y) continue;
        par[x] = y;
        sz[y] += sz[x];
        if (sz[y] == k) {
            forn(i, k) cout << w << ' ';
            cout << '\n';
            break;
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}