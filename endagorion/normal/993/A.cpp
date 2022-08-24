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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int lx = 1e9, rx = -1e9, ly = 1e9, ry = -1e9, ls = 1e9, rs = -1e9, ld = 1e9, rd = -1e9;
    forn(i, 4) {
        int x, y;
        cin >> x >> y;
        uin(lx, x);
        uax(rx, x);
        uin(ly, y);
        uax(ry, y);
    }

    forn(i, 4) {
        int x, y;
        cin >> x >> y;
        uin(ls, x + y);
        uax(rs, x + y);
        uin(ld, x - y);
        uax(rd, x - y);
    }

//    cerr << lx << ' ' << rx << ' ' << ly << ' ' << ry << ' ' << ls << ' ' << rs << ' ' << ld << ' ' << rd << '\n';

    bool ok = false;
    fore(x, -100, 100) fore(y, -100, 100) {
        ok |= lx <= x && x <= rx && ly <= y && y <= ry && ls <= x + y && x + y <= rs && ld <= x - y && x - y <= rd;
    }

    cout  << (ok ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}