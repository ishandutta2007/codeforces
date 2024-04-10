#include <iostream>
#include <vector>
#include <cmath>
#include <ctime>
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

struct TEdge {
    int from, to;
    int c, w;

    TEdge(int from = 0, int to = 0, int c = 0)
        : from(from)
        , to(to)
        , c(c)
        , w(0)
    {
    }
};

const int MAXN = 300;
vector<TEdge> edges;
vi e[MAXN];
int vis[MAXN];

void addEdge(int from, int to, int c) {
    e[from].pb(edges.size());
    edges.pb(TEdge(from, to, c));
    e[to].pb(edges.size());
    edges.pb(TEdge(to, from, 0));
}

bool dfs(int v, int t) {
    if (v == t) return true;
    if (vis[v]) return false;
    vis[v] = 1;
    forn(i, e[v].size()) {
        TEdge w = edges[e[v][i]];
        if (w.w >= w.c) continue;
        if (dfs(w.to, t)) {
            ++edges[e[v][i]].w;
            --edges[e[v][i] ^ 1].w;
            return true;
        }
    }
    return false;
}

bool isPrime(int x) {
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

vi g[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N;
    cin >> N;
    vi a(N);
    forn(i, N) cin >> a[i];
    forn(i, N) {
        if (a[i] % 2 == 0) addEdge(N, i, 2);
        else addEdge(i, N + 1, 2);
    }
    forn(i, N) forn(j, i) {
        if (!isPrime(a[i] + a[j])) continue;
        if (a[i] % 2 == 0) addEdge(i, j, 1);
        else addEdge(j, i, 1);
    }
    forn(i, N) {
        forn(j, MAXN) vis[j] = 0;
        if (!dfs(N, N + 1)) {
            cout << "Impossible\n";
            return 0;
        }
    }
    forn(i, edges.size()) {
        int x = edges[i].from, y = edges[i].to;
        if (x < N && y < N && edges[i].w > 0) {
            g[x].pb(y);
            g[y].pb(x);
        }
    }

    vvi ans;
    forn(i, N) vis[i] = 0;
    forn(i, N) {
        if (vis[i]) continue;
        int j = g[i][0], p = i;
        vi res;
        res.pb(i);
        vis[i] = 1;
        while (j != i) {
            vis[j] = 1;
            res.pb(j);
            int t = 0;
            while (g[j][t] == p) ++t;
            p = j;
            j = g[j][t];
        }
        ans.pb(res);
    }
    cout << ans.size() << '\n';
    forn(i, ans.size()) {
        cout << ans[i].size();
        for (int x: ans[i]) cout << ' ' << x + 1;
        cout << '\n';
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}