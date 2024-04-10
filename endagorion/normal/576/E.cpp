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

vector<int *> cht;
vi pv;

inline void applyChange(int *a, int b) {
    pv.pb(*a);
    cht.pb(a);
    *a = b;
}

inline void revertChange() {
    *cht.back() = pv.back();
    cht.pop_back();
    pv.pop_back();
}

const int MAXN = 500100, MAXK = 50;
int par[MAXK][MAXN], rk[MAXK][MAXN];
int side[MAXK][MAXN], mir[MAXK][MAXN];

int root(int *p, int x) {
    if (x == p[x]) return x;
    applyChange(&p[x], root(p, p[x]));
    return p[x];
}

void unite(int c, int x, int y) {
    x = root(par[c], x);
    y = root(par[c], y);
    if (rk[c][x] > rk[c][y]) swap(x, y);
    applyChange(&par[c][x], y);
    if (rk[c][x] == rk[c][y]) applyChange(&rk[c][x], rk[c][x] + 1);
}

void confront(int c, int x, int y) {
    x = root(par[c], x);
    y = root(par[c], y);
    if (x == y) {
        assert(side[c][x] != side[c][y]);
        return;
    }
    if (rk[c][x] > rk[c][y]) swap(x, y);
    if (rk[c][x] == rk[c][y]) applyChange(&rk[c][x], rk[c][x] + 1);
    int x1 = mir[c][x], y1 = mir[c][y];
    if (x1 != -1) x1 = root(par[c], x1);
    if (y1 != -1) y1 = root(par[c], y1);
    applyChange(&side[c][x], !side[c][y]);
    applyChange(&mir[c][x], y);
    applyChange(&mir[c][y], x);
    if (x1 != -1) unite(c, x1, y);
    if (y1 != -1) unite(c, y1, x);
}

const int MAXQ = 1 << 20;
vi fe[MAXQ];

pii e[MAXN];
int col[MAXN], ed[MAXN];
int ecol[MAXN];
int ans[MAXN];

void addEdge(int node, int ed, int l, int r, int L, int R) {
    if (max(l, L) >= min(r, R)) return;
    if (l <= L && R <= r) {
        fe[node].pb(ed);
        return;
    }
    int M = (L + R) / 2;
    addEdge(2 * node, ed, l, r, L, M);
    addEdge(2 * node + 1, ed, l, r, M, R);
}

void traverse(int node, int L, int R) {
    int chs = cht.size();
    for (int x: fe[node]) {
        if (ecol[x] != -1) confront(ecol[x], e[x].fi, e[x].se);
    }
    if (R - L == 1) {
        int x = e[ed[L]].fi, y = e[ed[L]].se;
        int c = col[L];
        x = root(par[c], x);
        y = root(par[c], y);
        ans[L] = x != y || side[c][x] != side[c][y];
        if (ans[L]) {
            ecol[ed[L]] = c;
        }
    } else {
        int M = (L + R) / 2;
        traverse(2 * node, L, M);
        traverse(2 * node + 1, M, R);
    }
    while (cht.size() > chs) revertChange();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M, K, Q;
    scanf("%d%d%d%d", &N, &M, &K, &Q);
    forn(i, M) scanf("%d%d", &e[i].fi, &e[i].se), --e[i].fi, --e[i].se;
    forn(j, K) forn(i, N) par[j][i] = i, side[j][i] = 0, mir[j][i] = -1;
    vi lst(M);
    forn(q, Q) {
        scanf("%d%d", &ed[q], &col[q]);
        --ed[q]; --col[q];
        addEdge(1, ed[q], lst[ed[q]], q, 0, Q);
        lst[ed[q]] = q + 1;
    }
    forn(i, M) addEdge(1, i, lst[i], Q, 0, Q);
    forn(i, M) ecol[i] = -1;
    traverse(1, 0, Q);
    forn(i, Q) printf("%s\n", (ans[i] ? "YES" : "NO"));

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}