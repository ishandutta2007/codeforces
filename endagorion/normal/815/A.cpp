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

const int maxn = 110;
int f[maxn][maxn];
int a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int n, m;
    cin >> n >> m;
    forn(i, n) forn(j, m) cin >> f[i][j];
    int bx = 0, bsc = 1e9;
    forn(x, 501) {
        bool ok = true;
        forn(i, n) a[i] = f[i][0] - x;
        b[0] = x;
        for1(i, m - 1) b[i] = f[0][i] - (f[0][0] - x);
        forn(i, n) ok &= a[i] >= 0;
        forn(i, m) ok &= b[i] >= 0;
        forn(i, n) forn(j, m) if (f[i][j] != a[i] + b[j]) ok = false;
        if (!ok) continue;
        int sc = 0;
        forn(i, n) sc += a[i];
        forn(i, m) sc += b[i];
        if (uin(bsc, sc)) bx = x;
    }
    if (bsc > 1e8) cout << -1 << '\n';
    else {
        int x = bx;
//        cerr << x << '\n';
//        a[0] = x;
        bool ok = true;
        forn(i, n) ok &= (a[i] = f[i][0] - x) >= 0;
        b[0] = x;
        for1(i, m - 1) b[i] = f[0][i] - (f[0][0] - x);
        cout << bsc << '\n';
        forn(i, n) forn(j, a[i]) cout << "row " << i + 1 << '\n';
        forn(i, m) forn(j, b[i]) cout << "col " << i + 1 << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}