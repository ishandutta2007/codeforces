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

i64 euclid(i64 a, i64 b, i64 &x, i64 &y) {
    if (!b) {
        x = 1;
        y = 0;
        return a;
    }
//    swap(a, b);
    i64 r = euclid(b, a % b, x, y);
    x -= (a / b) * y;
    swap(x, y);
    return r;
}

i64 solve(i64 x, i64 y, i64 n, i64 m) {
//    cerr << x << ' ' << y << ' ' << m << ' ' << n << '\n';
    i64 p, q;
    i64 r = euclid(m, n, p, q);
//    cerr << m << ' ' << p << ' ' << n << ' ' << q << ' ' << r << '\n';
//    cerr << r << '\n';
    if ((x - y) % r) return 1e18;
    i64 d = (x - y) / r;
    d *= p;
    d %= n / r;
    if (d < 0) d += n / r;
//    cerr << d << ' ' << n << ' ' << y + d * m << '\n';
//    cerr << y + d * m << '\n';
//    assert(m * d % n == (y - x + n) % n);o
    return y + d * m;
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
    forn(i, k) {
        i64 ans = 1e18;
        int x, y;
        cin >> x >> y;
        forn(sx, 2) forn(sy, 2) uin(ans, solve(sx ? 2 * n - x : x, sy ? 2 * m - y : y, 2 * n, 2 * m));
        if (ans > 1e17) ans = -1;
        cout << ans << endl;
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}