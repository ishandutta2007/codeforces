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

const int maxn = 500000;
vi e[maxn];
int w[maxn], bw[maxn], cw[maxn], ans[maxn];
int bch[maxn][2];
int n;

void put(int *v, int x) {
    forn(i, 2) {
        if (v[i] < x) swap(v[i], x);
    }
}

int get(int *v, int x) {
    forn(i, 2) {
        if (v[i] == x) x = -1;
        else return v[i];
    }
    return -1;
}

void dfs0(int v, int p) {
    w[v] = 1;
    bw[v] = 0;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs0(u, v);
        w[v] += w[u];
        cw[u] = bw[u];
        if (w[u] <= n / 2) uax(cw[u], w[u]);
        put(bch[v], cw[u]);
        uax(bw[v], cw[u]);
    }
}

void dfs(int v, int p, int b) {
//    cerr << v << ' ' << p << ' ' << b << '\n';
    bool ok = true;
    if (p != -1 && n - w[v] > n / 2) {
        ok = false;
        if (n - w[v] - b <= n / 2) ans[v] = 1;
    }
    for (int u: e[v]) {
        if (u != p) {
            if (w[u] > n / 2) {
                ok = false;
                if (w[u] - bw[u] <= n / 2) ans[v] = 1;
            }
        }
    }
    if (ok) ans[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        int nb = b;
        uax(nb, get(bch[v], cw[u]));
        if (n - w[v] <= n / 2) uax(nb, n - w[v]);
        dfs(u, v, nb);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    scanf("%d", &n);
    forn(i, n - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs0(0, -1);
    dfs(0, -1, 0);
    forn(i, n) printf("%d ", ans[i]);
    printf("\n");

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}