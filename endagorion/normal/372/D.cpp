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
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 150000;
const int maxk = 20;

vector<int> e[maxn];
int tim = 0;
int tin[maxn], par[maxn], d[maxn];
int jump[maxk][maxn];

int N, K;

void dfs(int v, int p) {
//    cerr << v << ' ' << p << '\n';
    tin[v] = tim++;
    par[v] = p;
    d[v] = p == -1 ? 0 : d[p] + 1;
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) {
            continue;
        }
        dfs(u, v);
    }
}

void build_jump() {
    forn(i, N) {
        jump[0][i] = par[i];
    }
    for (int k = 1; k < maxk; ++k) {
        forn(i, N) {
            jump[k][i] = jump[k - 1][i] == -1 ? -1 : jump[k - 1][jump[k - 1][i]];
        }
    }
}

int make_jump(int v, int dd) {
    for (int i = maxk - 1; i >= 0; --i) {
        if ((1 << i) <= dd) {
            v = jump[i][v];
            dd -= (1 << i);
        }
    }
    return v;
}

int lca(int u, int v) { 
    if (d[u] < d[v]) {
        swap(u, v);
    }
    u = make_jump(u, d[u] - d[v]);
    if (u == v) {
        return u;
    }
    for (int k = maxk - 1; k >= 0; --k) {
        if (jump[k][u] != jump[k][v]) {
            u = jump[k][u];
            v = jump[k][v];
        }
    }
    return par[u];
}

int path(int u, int v) {
    return d[u] + d[v] - 2 * d[lca(u, v)];
}

//template<class T>
set<pii>::iterator next(const set<pii>& inst, set<pii>::iterator it) {
    ++it;
    return it == inst.end() ? inst.begin() : it;
}


//template<class T>
set<pii>::iterator prev(const set<pii>& inst, set<pii>::iterator it) {
    if (it == inst.begin()) {
        it = inst.end();
    }
    --it;
    return it;
}


int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d%d", &N, &K);
    forn(i, N - 1) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u; --v;
        e[u].pb(v);
        e[v].pb(u);
    }

    dfs(0, -1);
    build_jump();

    int l = 1, r = N + 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        cerr << m << '\n';
        set<pii> vert;
        bool ok = false;
        forn(i, m) {
            vert.insert(mp(tin[i], i));
        }
        int sd = 0;
        for (auto it = vert.begin(); it != vert.end(); ++it) {
            sd += path(it->second, next(vert, it)->second);
        }
        if (sd <= 2 * (K - 1)) {
            ok = true;
        }
        for (int i = m; i < N; ++i) {
            vert.insert(mp(tin[i], i));
            auto it = vert.find(mp(tin[i], i));
            auto pit = prev(vert, it), nit = next(vert, it);
            sd += path(it->second, pit->second) + path(it->second, nit->second) - path(pit->second, nit->second);

            it = vert.find(mp(tin[i - m], i - m));
            pit = prev(vert, it), nit = next(vert, it);
            sd -= path(it->second, pit->second) + path(it->second, nit->second) - path(pit->second, nit->second);
            vert.erase(it);
            if (sd <= 2 * (K - 1)) {
                ok = true;
            }
        }
        if (ok) {
            l = m;
        } else {
            r = m;
        }
    }
    cout << l << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}