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

const int maxn = 100000;

struct TTriple {
    int a, b, c;

    explicit TTriple(int a = 0, int b = 0, int c = 0)
        : a(a)
        , b(b)
        , c(c)
    {
    }
};

vector<TTriple> ans;
vi e[maxn];
int vis[maxn];

bool dfs(int v, int p) {
    vis[v] = 1;
    int w = -1;
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) continue;
        if (vis[u] == 2) continue;
        bool use = vis[u] == 1 || dfs(u, v);
        if (use) {
            if (w == -1) w = u;
            else {
                ans.pb(TTriple(w, v, u));
                w = -1;
            }
        }
    }
    vis[v] = 2;
    if (w != -1) {
        ans.pb(TTriple(w, v, p));
        return false;
    } else {
        return true;
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, M;
    scanf("%d%d", &N, &M);
    forn(i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    bool ok = dfs(0, -1);
    if (ok) {
        forn(i, ans.size()) {
            printf("%d %d %d\n", ans[i].a + 1, ans[i].b + 1, ans[i].c + 1);
        }
    } else {
        printf("No solution\n");
    }

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}