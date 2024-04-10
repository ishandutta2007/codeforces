#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(c) (c).begin(), (c).end()
#define sz(c) int((c).size())
#define pb push_back
#define mp make_pair
#define fst first
#define snd second

#define FILE "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stdout)
#else
#define eprintf(args...) ;
#endif

using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;

const int MAXN = (int)2e5 + 100;
const int MOD = (int)1e9 + 7;

int n;
int a[MAXN];
vi g[MAXN];

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    forn(i, n) {
        cin >> a[i];
        a[i] %= MOD;
        a[i] += MOD;
        a[i] %= MOD;
    }
    forn(i, n) {
        g[i].clear();
    }
    forn(i, n - 1) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    return 1;
}

int cnt[2][MAXN], h[MAXN];
int sz[MAXN];

void dfs(int v, int p = -1, int ch = 0) {
    sz[v] = 1;
    h[v] = ch;
    cnt[0][v] = cnt[1][v] = 0;
    cnt[ch][v]++;

    for (int i = 0; i < sz(g[v]); i++) {
        if (g[v][i] == p) {
            swap(g[v][i], g[v].back());
            g[v].pop_back();
            i--;
            continue;
        }

        int to = g[v][i];
        dfs(to, v, ch ^ 1);
        sz[v] += sz[to];
        forn(j, 2) {
            cnt[j][v] += cnt[j][to];
        }
    }
}

void add(int &x, int y) {
    x += y;
    if (x >= MOD) {
        x -= MOD;
    }
}

int sub(int x, int y) {
    x -= y;
    if (x < 0) {
        x += MOD;
    }
    return x;
}

int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

int ans;

void calc(int v) {
/*
    eprintf("cnts(%d): %d %d\n", v, cnt[0][v], cnt[1][v]);

    int aadd = 0;
    // calc lower
    int ps = cnt[h[v]][v], ms = cnt[h[v] ^ 1][v];
    int mult = sub(ps, ms);
    add(aadd, mul(mul(mult, a[v]), n - sz[v] + 1));
    eprintf("ps=%d ms=%d mul %d\n", ps, ms, n - sz[v] + 1);

    // calc upper
    ps = cnt[h[v]][0] - ps, ms = cnt[h[v] ^ 1][0] - ms;
    ps++;
    mult = sub(ps, ms);
    add(aadd, mul(mul(mult, a[v]), sz[v]));

    aadd = sub(aadd, a[v]);
    eprintf("ps=%d ms=%d mul %d\n", ps, ms, sz[v]);

    eprintf("added(%d)=%d\n", v, aadd);

    add(ans, aadd);
*/
    for (auto to: g[v]) {
        calc(to);
        
        int ps = cnt[h[v]][to], ms = cnt[h[v] ^ 1][to];
        int mult = sub(ps, ms);
        add(ans, mul(mul(mult, a[v]), n - sz[to]));
    }


    int ps = cnt[h[v]][0] - cnt[h[v]][v], ms = cnt[h[v] ^ 1][0] - cnt[h[v] ^ 1][v];
    int mult = sub(ps, ms);
    add(ans, mul(mul(mult, a[v]), sz[v]));

    add(ans, mul(a[v], n));
}

int solve() {
    eprintf("n=%d\n", n);
    dfs(0);
    ans = 0;
    calc(0);
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

#ifdef LOCAL
    freopen(FILE ".in", "r", stdin);
    freopen(FILE ".out", "w", stdout);
#endif

    while (read()) {
        cout << solve() << '\n';
    }

#ifdef LOCAL
    eprintf("Time %.5f\n", clock() * 1.0 / CLOCKS_PER_SEC);
#endif
}