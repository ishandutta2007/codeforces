#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
vector<int> g[100000];
int sz[100000];
bool used[100000];
LL ans = 0;

inline void calcSizes(int v, int p) {
    sz[v] = 1;
    for (int &to : g[v]) if (used[to] && to != p) {
        calcSizes(to, v);
        sz[v] += sz[to];
    }
}

int delta;
int cnt[20][2];

void add(int v, int par, int val) {
    forn(i, 20) cnt[i][(val >> i) & 1] += delta;
    for (int to : g[v]) if (used[to] && to != par) {
        add(to, v, val ^ a[to]);
    }
}

void dfs(int v, int par, int val) {
    forn(i, 20) ans += (LL)cnt[i][1 ^ ((val >> i) & 1)] << i;
    ans += 2 * val;
    for (int to : g[v]) if (used[to] && to != par) {
        dfs(to, v, val ^ a[to]);
    }
}

void solve(int v) {
    delta = 1;
    for (int to : g[v]) if (used[to]) {
        add(to, v, a[to]);
    }
    for (int to : g[v]) if (used[to]) {
        delta = -1;
        add(to, v, a[to]);

        dfs(to, v, a[v] ^ a[to]);

        delta = 1;
        add(to, v, a[to]);
    }
    delta = -1;
    for (int to : g[v]) if (used[to]) {
        add(to, v, a[to]);
    }
}

void cd(int v) {
    calcSizes(v, -1);
    int tot = sz[v];
    bool ok = false;
    int p = -1;
    while (!ok) {
        ok = true;
        for (int to : g[v]) if (used[to] && to != p && sz[to] * 2 > tot) {
            p = v;
            v = to;
            ok = false;
            break;
        }
    }
    solve(v);
    used[v] = false;
    for (int to : g[v]) if (used[to]) {
        cd(to);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    forn(i, n) used[i] = true;
    cd(0);
    assert(ans % 2 == 0);
    ans /= 2;
    forn(i, n) ans += a[i];
    cout << ans << endl;
    return 0;
}