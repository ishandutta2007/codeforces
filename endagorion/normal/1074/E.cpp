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

const int maxn = 20;
int n, m;
int a[maxn * maxn], inva[maxn * maxn];

vvi ops;

void swp(int x, int y) {
    a[inva[x]] = y;
    a[inva[y]] = x;
    swap(inva[x], inva[y]);
}

void shift(vi v, bool make = true) {
    assert(set<int>(all(v)).size() == v.size());
    forn(i, v.size()) {
        int x = v[i], y = v[(i + 1) % v.size()];
        assert(x >= 0 && x < n * m);
        assert(abs(x - y) == 1 || abs(x - y) == m);
    }
    for (auto &w: v) w = a[w];
    if (make) ops.pb(v);
    for (int i = v.size() - 1; i > 0; --i) swp(v[i], v[0]);

//    forn(i, n * m) cerr << a[i] << " \n"[i % m == m - 1];
//    cerr << '\n';
}

void move_up(int x) {
    int p = inva[x];
    if (p % m != m - 1) shift({p, p - m, p - m + 1, p + 1});
    else shift({p, p - m, p - m - 1, p - 1});
}

void move_down(int x) {
    int p = inva[x];
    if (p % m != m - 1) shift({p, p + m, p + m + 1, p + 1});
    else shift({p, p + m, p + m - 1, p - 1});
}

void move_left(int x) {
    int p = inva[x];
    shift({p, p - 1, p - 1 + m, p + m});
}

void move_right(int x) {
    int p = inva[x];
    shift({p, p + 1, p + 1 + m, p + m});
}

void move_towards(int x, int c) {
    if (inva[x] / m == n - 1) move_up(x);
    while (inva[x] % m < c % m) move_right(x);
    while (inva[x] % m > c % m) move_left(x);
    while (inva[x] / m > c / m) move_up(x);
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
    ::n = n; ::m = m;
    forn(i, n * m) cin >> a[i], --a[i], inva[a[i]] = i;
    forn(i, n - 2) {
        forn(j, m - 2) move_towards(i * m + j, i * m + j);
        int v = i * m + m - 2, u = i * m + m - 1;
        if (inva[v] == v && inva[u] == u) continue;
        if (inva[v] == v) move_right(v);
        else if (inva[v] != u) {
            move_towards(v, u + m);
            move_up(v);
        }
        if (inva[u] == v) {
            move_left(v);
            move_left(a[u + m]);
            move_left(a[u + m]);
            move_right(v);
            move_right(a[v + m]);
            move_right(a[v + m]);
        } else move_towards(u, u + m);
        if (inva[u] == v) {
            move_down(v);
            move_down(v);
            move_down(u);
            move_up(v);
            move_up(v);
        } else move_towards(u, u + m);
        shift({u, v, v + m, u + m});
    }

    forn(j, m - 2) {
        int v = (n - 2) * m + j, u = (n - 1) * m + j;
        move_towards(u, v);
        if (inva[v] != u) move_towards(v, v + 1);
        else {
            move_right(u);
            move_right(u);
            move_right(v);
            move_left(u);
            move_left(u);
        }
        move_down(u);
    }

    while (inva[n * m - 1] != n * m - 1) move_up(a[n * m - 1]);
    while (1) {
        bool ok = true;
        for1(i, 2) for1(j, 2) ok &= inva[(n - i) * m + (m - j)] == (n - i) * m + (m - j);
        if (ok) break;
        if (rand() % 2) {
           move_right(a[(n - 3) * m + m - 2]);
           move_left(a[(n - 2) * m + m - 2]);
           move_left(a[(n - 3) * m + m - 1]);
           move_right(a[(n - 2) * m + m - 3]);
        } else {
           move_right(a[(n - 3) * m + m - 2]);
           move_right(a[(n - 3) * m + m - 3]);
           shift({(n - 3) * m + m - 1, (n - 3) * m + m - 2, (n - 3) * m + m - 3, (n - 2) * m + m - 3, (n - 2) * m + m - 2, (n - 2) * m + m - 1});
        }
    }

    forn(i, n * m) assert(a[i] == i);
    cout << ops.size() << '\n';
    for (auto w: ops) {
        cout << w.size();
        for (int x: w) cout << ' ' << x + 1;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}