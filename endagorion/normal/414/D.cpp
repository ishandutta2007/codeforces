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

vi e[maxn];
vi d;
i64 pr[maxn];

void dfs(int v, int p, int dd) {
    if (dd) d.pb(dd);
    forn(i, e[v].size()) {
        int u = e[v][i];
        if (u == p) continue;
        dfs(u, v, dd + 1);
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    int N, K, P;
    scanf("%d%d%d", &N, &K, &P);
    forn(i, N - 1) {
        int x, y;
        scanf("%d%d", &x, &y);
        --x; --y;
        e[x].pb(y);
        e[y].pb(x);
    }
    dfs(0, -1, 0);
    sort(all(d));
    pr[0] = 0;
    forn(i, N - 1) pr[i + 1] = pr[i] + d[i];
    int ans = 0;
    int i = 0;
    for (int q = 1; q <= N; ++q) {
        while (i < N - 1 && d[i] <= q) ++i;
        int l = 0, r = min(K + 1, i + 1);
        while (r - l > 1) {
            int m = (l + r) / 2;
            i64 T = 1LL * m * q - (pr[i] - pr[i - m]);
            if (T <= P) l = m;
            else r = m;
        }
        ans = max(ans, l);
    }
    cout << ans << '\n';

#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}