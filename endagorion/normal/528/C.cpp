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

const int MAXN = 500000;
vector<pii> e[MAXN];
int d[MAXN], vis[MAXN];

vector<pii> ans;
int c;

void dfs(int v) {
    for (; d[v] < e[v].size(); ++d[v]) {
        int u = e[v][d[v]].fi, id = e[v][d[v]].se;
        if (vis[id]) continue;
        vis[id] = 1;
        dfs(u);
        ans.pb(mp(v, u));
        ++c;
    }
}

int p[MAXN];

int get_root(int v) {
    if (p[v] == v) return v;
    return p[v] = get_root(p[v]);
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
    scanf("%d%d", &N, &M);
    forn(i, N) p[i] = i;
    forn(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(mp(y, i));
        e[y].pb(mp(x, i));
        p[get_root(x)] = get_root(y);
    }

    vector<pii> odd;
    forn(i, N) {
        if (e[i].size() % 2 == 0) continue;
        odd.pb(mp(get_root(i), i));
    }
    sort(all(odd));
    forn(i, odd.size() / 2) {
        int x = odd[(2 * i + 1) % odd.size()].se, y = odd[(2 * i + 2) % odd.size()].se;
        e[x].pb(mp(y, M));
        e[y].pb(mp(x, M));
        ++M;
    }
    forn(i, N) {
        c = 0;
        dfs(i);
        if (c % 2) {
            int x = ans.back().fi;
            ans.pb(mp(x, x));
        }
    }
    forn(i, ans.size() / 2) swap(ans[2 * i].fi, ans[2 * i].se);
    printf("%d\n", (int)ans.size());
    forn(i, ans.size()) {
        printf("%d %d\n", ans[i].fi + 1, ans[i].se + 1);
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}