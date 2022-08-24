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

int n;

int ask(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 + 1 << ' ' << y1 + 1 << ' ' << x2 << ' ' << y2 << endl;
    int x;
    cin >> x;
    return x;
}

int tryx() {
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        (ask(0, 0, m, n) >= 1 ? r : l) = m;
    }
    if (ask(0, 0, r, n) == 1 && ask(r, 0, n, n) == 1) return r;
    return -1;
}

int tryy() {
    int l = 0, r = n;
    while (r - l > 1) {
        int m = (l + r) / 2;
        (ask(0, 0, n, m) >= 1 ? r : l) = m;
    }
    if (ask(0, 0, n, r) == 1 && ask(0, r, n, n) == 1) return r;
    return -1;
}


pair<pii, pii> locate(int lx, int ly, int rx, int ry) {
    ford(i, 20) {
        int sh = 1 << i;
        if (lx + sh < rx && ask(lx + sh, ly, rx, ry)) lx += sh;
        if (rx - sh > lx && ask(lx, ly, rx - sh, ry)) rx -= sh;
        if (ly + sh < ry && ask(lx, ly + sh, rx, ry)) ly += sh;
        if (ry - sh > ly && ask(lx, ly, rx, ry - sh)) ry -= sh;
    }
    return mp(mp(lx, ly), mp(rx, ry));
}


void print(pair<pii, pii> p) {
    cout << p.fi.fi + 1 << ' ' << p.fi.se + 1 << ' ' << p.se.fi << ' ' << p.se.se << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;

    cin >> n;
    int p;
    pair<pii, pii> r1, r2;
    if ((p = tryx()) != -1) {
        r1 = locate(0, 0, p, n);
        r2 = locate(p, 0, n, n);
    } else if ((p = tryy()) != -1) {
        r1 = locate(0, 0, n, p);
        r2 = locate(0, p, n, n);
    } else assert(false);
    cout << "! ";
    print(r1);
    print(r2);
    cout << endl;

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}