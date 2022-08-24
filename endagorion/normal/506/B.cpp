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

const int MAXN = 150000;
vi e[MAXN], re[MAXN], be[MAXN];
int bc[MAXN], cc[MAXN];
int vis[MAXN];

int N, M;

void clear_vis() {
    forn(i, N) vis[i] = 0;
}

void bdfs(int v, int b) {
    if (vis[v]) return;
    vis[v] = 1;
    bc[v] = b;
    for (int u: be[v]) bdfs(u, b);
}

vi ord;

void ord_dfs(int v) {
    if (vis[v]) return;
    vis[v] = 1;
    for (int u: e[v]) {
        if (vis[u] == 2) continue;
        if (vis[u] == 1) cc[bc[v]] = 1;
        ord_dfs(u);
    }
    vis[v] = 2;
}

int comp_dfs(int v) {
    if (vis[v]) return 0;
    vis[v] = 1;
    int res = 1;
    for (int u: re[v]) res += comp_dfs(u);
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.precision(10);
    cout << fixed;
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
#endif

    cin >> N >> M;
    forn(i, M) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        e[x].pb(y);
        re[y].pb(x);
        be[x].pb(y);
        be[y].pb(x);
    }
    int bcomp = 0;
    forn(i, N) {
        if (vis[i]) continue;
        bdfs(i, bcomp);
        ++bcomp;
    }
    clear_vis();
    forn(i, N) {
        ord_dfs(i);
    }
    int ans = N;
    forn(i, bcomp) if (!cc[i]) --ans;
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}