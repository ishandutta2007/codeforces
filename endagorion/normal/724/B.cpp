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

bool isId(const vi &v) {
    forn(i, v.size()) if (v[i] != i) return 0;
    return 1;
}

bool can(vi v, pii p) {
    if (isId(v)) return true;
    int n = v.size();
    bool ok = false;
    forn(i, n) forn(j, i) {
        swap(v[i], v[j]);
        ok |= isId(v);
        swap(v[i], v[j]);
    }
    if (p.fi < 0) return ok;
    forn(i, n) forn(j, i) {
        vi u = v;
        swap(v[p.fi], v[p.se]);
        swap(v[i], v[j]);
        swap(v[p.fi], v[p.se]);
        ok |= isId(v);
        v = u;
    }
    return ok;
}

bool can2(vvi a, pii p) {
    bool ok = true;
    for (vi v: a) ok &= can(v, p);
    return ok;
}

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
    vvi a(n, vi(m));
    forn(i, n) forn(j, m) cin >> a[i][j], --a[i][j];
    bool ok = can2(a, {-1, -1});
    forn(i, m) forn(j, i) {
        forn(k, n) swap(a[k][i], a[k][j]);
        ok |= can2(a, {i, j});
        forn(k, n) swap(a[k][i], a[k][j]);
    }
    cout << (ok ? "YES" : "NO") << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}