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

const int MAXN = 100001, LOG = 17;
vi e[MAXN];
int up[LOG + 1][MAXN];
int h[MAXN];
vi x[LOG + 1][MAXN];

void dfs(int v, int p) {
    up[0][v] = p;
    for (int u: e[v]) {
        if (u == p) continue;
        h[u] = h[v] + 1;
        dfs(u, v);
    }
}

int jmp(int v, int d) {
    ford(i, LOG) {
        if ((1 << i) <= d) {
            v = up[i][v];
            d -= 1 << i;
        }
    }
    return v;
}

int lca(int u, int v) {
    if (h[u] < h[v]) swap(u, v);
    u = jmp(u, h[u] - h[v]);
    if (u == v) return u;
    ford(i, LOG) {
        int uu = up[i][u], vv = up[i][v];
        if (uu != vv) u = uu, v = vv;
    }
    return up[0][u];
}

vi merg(const vi &a, const vi &b, int A) {
    vi v;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size() && v.size() < A) {
        if (a[i] == b[j]) {
            v.pb(a[i]);
            ++i; ++j;
            continue;
        }
        if (a[i] < b[j]) v.pb(a[i++]);
        else v.pb(b[j++]);
    }
    while (i < a.size() && v.size() < A) v.pb(a[i++]);
    while (j < b.size() && v.size() < A) v.pb(b[j++]);
    return v;
}

void upq(int v, int d, int a, vector<vi *> &res) {
//    vi res;
    ford(i, LOG) {
        if ((1 << i) <= d) {
            res.pb(&x[i][v]);
            v = up[i][v];
            d -= 1 << i;
        }
    }
//    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    int N, M, Q;
//    cin >> N >> M >> Q; 
    scanf("%d%d%d", &N, &M, &Q);
    forn(i, N - 1) {
        int x, y;
//        cin >> x >> y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, M) {
        int v;
//        cin >> v;
        scanf("%d", &v);
        --v;
        x[0][v].pb(i);
    }
    forn(i, N) {
        sort(all(x[0][i]));
        if (x[0][i].size() > 10) x[0][i].resize(10);
    }
    dfs(0, 0);
    forn(i, LOG) forn(j, N) {
        up[i + 1][j] = up[i][up[i][j]];
        x[i + 1][j] = merg(x[i][j], x[i][up[i][j]], 10);
    }
    cerr << "built\n";
    forn(q, Q) {
        int u, v, a;
//        cin >> u >> v >> a;
        scanf("%d%d%d", &u, &v, &a);
        --u; --v;
        int w = lca(u, v);
        vector<vi*> res;
        upq(u, h[u] - h[w] + 1, a, res);
        upq(v, h[v] - h[w], a, res);
        vi ans;
        vi ind(res.size());
        set<pii> s;
        forn(i, res.size()) {
            if (!res[i]->empty()) s.insert(mp((*res[i])[0], i));
        }
        while (!s.empty() && ans.size() < a) {
            int x = s.begin()->fi, j = s.begin()->se;
            //if (ans.empty() || ans.back() != x) ans.pb(x);
            ans.pb(x);
            s.erase(s.begin());
            ++ind[j];
            if (ind[j] < res[j]->size()) s.insert(mp((*res[j])[ind[j]], j));
        }
        printf("%d", (int)ans.size());
        for (int x: ans) printf(" %d", x + 1);
        printf("\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}