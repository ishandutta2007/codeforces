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
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }

pair<i64, i64> solve(i64 x, i64 y, i64 h, i64 m, i64 a) {
    vi64 s(m, -1);
    i64 i;
    for (i = 0; s[h] == -1; h = (h * x + y) % m, ++i) {
        s[h] = i;
    }
    i64 predp = s[h], per = i - predp;
    if (s[a] == -1) return mp(-1, -1);
    if (s[a] < predp) return mp(s[a], -1);
    return mp(s[a], per);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    i64 m, h1, a1, x1, y1, h2, a2, x2, y2;
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;
    pair<i64, i64> p1 = solve(x1, y1, h1, m, a1), p2 = solve(x2, y2, h2, m, a2);
    i64 ans = -1;
    if (p1.fi == -1 || p2.fi == -1) ans = -1;
    else for (i64 x = p1.fi, i = 0; i < 2 * m; ++i, x += p1.se) {
        if (x >= p2.fi) {
            if (p2.se == -1 && x == p2.fi || (p2.se != -1 && x % p2.se == p2.fi % p2.se)) ans = x;
        }
        if (p1.se == -1 || ans >= 0) break;
    }                          
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}