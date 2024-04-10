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
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;

const int maxn = 200000;
int par[maxn], s[maxn];
int a[maxn];
vi e[maxn];

i64 tot = 0;

int root(int v) {
    if (v == par[v]) return v;
    return par[v] = root(par[v]);
}

void unite(int u, int v) {
    u = root(u);
    v = root(v);
    if (u == v) return;
    tot -= 1LL * s[u] * s[u];
    tot -= 1LL * s[v] * s[v];
    par[v] = u;
    s[u] += s[v];
    tot += 1LL * s[u] * s[u];
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, N) scanf("%d", &a[i]);
    forn(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    forn(i, N) {
        par[i] = i;
        s[i] = 1;
        ++tot;
    }
    vector< pair<int, int> > ord(N);
    forn(i, N) ord[i] = mp(a[i], i);
    sort(rall(ord));
    i64 ans = 0;
    vi vis(N);
    forn(i, N) {
        int v = ord[i].second;
        i64 t1 = tot;
        forn(j, e[v].size()) {
            int u = e[v][j];
            if (!vis[u]) continue;
            unite(u, v);
        }
        vis[v] = 1;
        ans += a[v] * (tot - t1);
    }
    printf("%.10lf\n", 1.0 * ans / N / (N - 1));

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}