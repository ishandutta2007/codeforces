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

const i64 P = 1000000 + 3;
const int maxn = 1000000;

i64 deg(i64 x, i64 d) {
    if (d < 0) d += P - 1;
    d %= P;
    i64 y = 1;
    while (d) {
        if (d & 1) y *= x, y %= P;
        x *= x, x %= P;
        d /= 2;
    }
    return y;
}

void add(i64 &x, i64 y) {
    x += y; x %= P;
}

vvi64 mul(vvi64 a, vvi64 b) {
    int n = a.size();
    vvi64 c(n, vi64(n));
    forn(i, n) forn(j, n) forn(k, n) add(c[i][j], a[i][k] * b[k][j]);
    return c;
}

vvi64 deg(vvi64 a, i64 d) {
    int n = a.size();
    vvi64 c(n, vi64(n));
    forn(i, n) c[i][i] = 1;
    while (d) {
        if (d & 1) c = mul(c, a);
        a = mul(a, a);
        d /= 2;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int c, w, h;
    cin >> c >> w >> h;

    vvi64 m(w + 1, vi64(w + 1));
    forn(i, w + 1) m[0][i] = deg(h, i);
    forn(i, w) m[i + 1][i] = 1;
    vvi64 mm = deg(m, c);
    i64 ans = mm[0][0] + mm[0][1];
    ans %= P;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}