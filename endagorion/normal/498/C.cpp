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
    int from, to, c, w;
    int id;

    TEdge(int from = 0, int to = 0, int c = 0, int w = 0, int id = 0)
        : from(from)
        , to(to)
        , c(c)
        , w(w)
        , id(id)
    {
    }
};

vector<TEdge> e;
vi edges[110];
int vis[110];

void addEdge(int from, int to, int c, int id = -1) {
    edges[from].pb(e.size());
    e.pb(TEdge(from, to, c, 0, id));
    edges[to].pb(e.size());
    e.pb(TEdge(to, from, 0, 0, id));
}

bool dfs(int v, int to) {
    if (v == to) return true;
    if (vis[v]) return false;
    vis[v] = 1;
    forn(i, edges[v].size()) {
        TEdge w = e[edges[v][i]];
        if (w.w >= w.c) continue;
        if (dfs(w.to, to)) {
            ++e[edges[v][i]].w;
            --e[edges[v][i] ^ 1].w;
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M;
    cin >> N >> M;
    vi a(N);
    forn(i, N) cin >> a[i];
    vector<pii> b(M);
    forn(i, N) {
        if ((i & 1) == 0) addEdge(N, i, 1e9, 0);
        else addEdge(i, N + 1, 1e9, 0);
    }
    forn(i, M) {
        cin >> b[i].fi >> b[i].se;
        --b[i].fi; --b[i].se;
        if (b[i].fi & 1) swap(b[i].fi, b[i].se);
        addEdge(b[i].fi, b[i].se, 1e9, 0);
    }
    set<int> s;
    forn(i, N) {
        int x = a[i];
        for (int j = 2; j * j <= x; ++j) {
            if (x % j) continue;
            s.insert(j);
            while (x % j == 0) x /= j;
        }
        if (x > 1) s.insert(x);
    }

    int ans = 0;
    for (int x: s) {
        forn(i, e.size()) {
            e[i].w = 0;
        }
        forn(i, N) {
            int y = a[i];
            e[2 * i].c = 0;
            while (y % x == 0) {
                y /= x;
                ++e[2 * i].c;
            }
        }
        while (1) {
            forn(i, N + 2) vis[i] = false;
            if (dfs(N, N + 1)) ++ans;
            else break;
        }
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}