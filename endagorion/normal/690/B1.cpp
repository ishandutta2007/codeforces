#include <iostream>
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

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

string s[50];

int f(int x, int lx, int rx) {
    if (lx <= x && x <= rx) return 2;
    if (x == lx - 1 || x == rx + 1) return 1;
    return 0;
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
    forn(i, n) cin >> s[i];
    int lx = 1e9, rx = -1e9, ly = 1e9, ry = -1e9;
    forn(i, n) forn(j, n) {
        if (s[i][j] == '4') uin(lx, i), uax(rx, i), uin(ly, j), uax(ry, j);
    }
    if (rx < 0) {
        cout << "No\n";
        return 0;
    }

    bool ok = true;
    forn(i, n) forn(j, n) {
        int ix = f(i, lx, rx), iy = f(j, ly, ry);
        int d;
        if (ix == 2 && iy == 2) d = 4;
        else if (ix == 0 || iy == 0) d = 0;
        else if (ix == 1 && iy == 1) d = 1;
        else d = 2;
        ok &= s[i][j] == (char)(d + '0');
    }
    cout << (ok ? "Yes" : "No") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}