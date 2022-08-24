#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
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

template<class T>
bool uin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool uax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const int MAXN = 110000, LOG = 20;

vi e[MAXN];
int par[MAXN], d[MAXN], sz[MAXN];
int up[LOG + 1][MAXN];

int N;

void dfs(int v, int p) {
    par[v] = p;
    d[v] = (p == -1 ? 0 : d[p] + 1);
    sz[v] = 1;
    for (int u: e[v]) {
        if (u == p) continue;
        dfs(u, v);
        sz[v] += sz[u];
    }
}

int jump_up(int v, int k) {
    ford(i, LOG) {
        if ((1 << i) <= k) {
            k -= 1 << i;
            v = up[i][v];
        }
    }
    return v;
}

int lca(int u, int v) {
    if (d[u] > d[v]) swap(u, v);
    v = jump_up(v, d[v] - d[u]);
    if (u == v) return u;
    ford(i, LOG) {
        if (up[i][u] != up[i][v]) {
            u = up[i][u];
            v = up[i][v];
        }
    }
    return up[0][u];
}

int dist(int u, int v) {
    int w = lca(u, v);
    return d[u] + d[v] - 2 * d[w];
}

int move_to(int v, int u, int k) {
    int w = lca(u, v);
    if (k <= d[v] - d[w]) return jump_up(v, k);
    return jump_up(u, d[u] + d[v] - 2 * d[w] - k);
}

int wto(int u, int v) {
    int w = move_to(u, v, 1);
    if (par[u] == w) return N - sz[u];
    return sz[w];
}

int main() {
    ios::sync_with_stdio(false);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N;
    forn(i, N - 1) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        e[a].pb(b);
        e[b].pb(a);
    }
    dfs(0, -1);
    forn(i, N) up[0][i] = par[i];
    for1(k, LOG) forn(i, N) {
        up[k][i] = (up[k - 1][i] == -1 ? -1 : up[k - 1][up[k - 1][i]]);
    }

    int M;
    cin >> M;
    forn(i, M) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int d = dist(u, v);
        if (!d) cout << N << '\n';
        else if (d % 2) cout << 0 << '\n';
        else {
            int w = move_to(u, v, d / 2);
            cout << N - wto(w, u) - wto(w, v) << '\n';
        }
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}