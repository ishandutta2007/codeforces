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

const int maxn = 301;
string s[maxn][maxn], t[maxn][maxn];
string ss[maxn][maxn];
vector<pair<pii, pii> > q1, q2;

bool DEBUG = 0;

int n, m;

void debug_transfer(int x1, int y1, int x2, int y2) {
    assert(x1 == x2 || y1 == y2);
    assert(x1 != x2 || y1 != y2);
    assert(!ss[x1][y1].empty());
    char c = ss[x1][y1].back();
    ss[x1][y1].resize(ss[x1][y1].size() - 1);
    ss[x2][y2] = c + ss[x2][y2];

    forn(i, n) {
        forn(j, m) cerr << ss[i][j] << ' ';
        cerr << '\n';
    }
    cerr << '\n';
}

void transfer(int x1, int y1, int x2, int y2, bool rev = false) {
    if (x1 == x2 && y1 == y2) return;
    if (x1 == x2 || y1 == y2) {
        if (!rev) q1.pb({{x1, y1}, {x2, y2}});
        else q2.pb({{x2, y2}, {x1, y1}});
//        cout << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 + 1 << ' ' << y2 + 1 << '\n';
        return;
    }
    transfer(x1, y1, x1, y2, rev);
    transfer(x1, y2, x2, y2, rev);
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
    forn(i, n) forn(j, m) {
        cin >> s[i][j];
        ss[i][j] = s[i][j];
        reverse(all(s[i][j]));
    }
    forn(i, n) forn(j, m) cin >> t[i][j];
    for1(i, n - 1) {
        int c0 = 0, c1 = 0;
        forn(j, 2) for (auto w: s[i][j]) {
            if (j == w - '0') transfer(i, j, 0, j);
            else transfer(i, j, i, w - '0'), ++(j ? c0 : c1);
        }
        forn(j, c0) transfer(i, 0, 0, 0);
        forn(j, c1) transfer(i, 1, 0, 1);
    }
    {
        int c00 = 0, c11 = 0;
        forn(j, 2) for (auto w: s[0][j]) {
            if (j == w - '0') {
                ++(j ? c11 : c00);
                transfer(0, j, 1, j);
            } else transfer(0, j, 0, w - '0');
        }
        forn(j, c00) transfer(1, 0, 0, 0);
        forn(j, c11) transfer(1, 1, 0, 1);
    }


    forn(i, n) fore(j, 2, m - 1) {
        for (auto w: s[i][j]) transfer(i, j, 0, w - '0');
    }

    for1(i, n - 1) {
        int c0 = 0, c1 = 0;
        forn(j, 2) for (auto w: t[i][j]) {
            if (j == w - '0') transfer(i, j, 0, j, 1);
            else transfer(i, j, i, w - '0', 1), ++(j ? c0 : c1);
        }
        forn(j, c0) transfer(i, 0, 0, 0, 1);
        forn(j, c1) transfer(i, 1, 0, 1, 1);
    }
    {
        int c00 = 0, c11 = 0;
        forn(j, 2) for (auto w: t[0][j]) {
            if (j == w - '0') {
                ++(j ? c11 : c00);
                transfer(0, j, 1, j, 1);
            } else transfer(0, j, 0, w - '0', 1);
        }
        forn(j, c00) transfer(1, 0, 0, 0, 1);
        forn(j, c11) transfer(1, 1, 0, 1, 1);
    }

    forn(i, n) fore(j, 2, m - 1) {
        for (auto w: t[i][j]) transfer(i, j, 0, w - '0', 1);
    }


    cout << q1.size() + q2.size() << '\n';
    reverse(all(q2));
    for (auto w: q1) {
        cout << w.fi.fi + 1 << ' ' << w.fi.se + 1 << ' ' << w.se.fi + 1 << ' ' << w.se.se + 1 << '\n';
        if (DEBUG) debug_transfer(w.fi.fi, w.fi.se, w.se.fi, w.se.se);
    }
    for (auto w: q2) {
        cout << w.fi.fi + 1 << ' ' << w.fi.se + 1 << ' ' << w.se.fi + 1 << ' ' << w.se.se + 1 << '\n';
        if (DEBUG) debug_transfer(w.fi.fi, w.fi.se, w.se.fi, w.se.se);
    }

    if (DEBUG) forn(i, n) forn(j, m) assert(ss[i][j] == t[i][j]);

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}