#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[200005];
char buf[200005];
int a[200005];
int sz[200005];
bool used[200005];
LL ans[200005];

inline void calcSizes(int v, int p) {
    sz[v] = 1;
    for (int &to : g[v]) if (used[to] && to != p) {
        calcSizes(to, v);
        sz[v] += sz[to];
    }
}

int cnt[1 << 20];
bool mark[1 << 20];

int delta;
void add(int v, int p, int mask) {
    cnt[mask] += delta;
    for (int to : g[v]) if (used[to] && to != p) {
        add(to, v, mask ^ a[to]);
    }
}

int globV;

LL dfs(int v, int p, int mask) {
    LL res = 0;
    for (int to : g[v]) if (used[to] && to != p) {
        res += dfs(to, v, mask ^ a[to]);
    }
    if (mark[mask]) {
        ++ans[globV];
    }
    res += cnt[mask];
    forn(i, 20) {
        res += cnt[mask ^ (1 << i)];
    }
    ans[v] += 2 * res;
    return res;
}

void solve(int v) {
    delta = 1;
    for (int to : g[v]) if (used[to]) {
        add(to, v, a[to]);
    }

    globV = v;

    for (int to : g[v]) if (used[to]) {
        delta = -1;
        add(to, v, a[to]);

        ans[v] += dfs(to, v, a[to] ^ a[v]);

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
//    freopen("input.txt", "r", stdin);
    mark[0] = true;
    forn(i, 20) mark[1 << i] = true;

    if (0) {
        mt19937 mt(123);
        n = 200000;
        for (int i = 1; i < n; ++i) {
            int par = mt() % i;
            g[i].pb(par);
            g[par].pb(i);
        }
        forn(i, n) a[i] = 1 << (mt() % 20);
    } else {
        scanf("%d", &n);
        forn(i, n - 1) {
            int from, to;
            scanf("%d%d", &from, &to), --from, --to;
            g[from].pb(to);
            g[to].pb(from);
        }
        scanf("%s", buf);
        forn(i, n) a[i] = buf[i] - 'a';
        forn(i, n) a[i] = 1 << a[i];
    }
    forn(i, n) used[i] = true;
    cnt[0] = 1;
    cd(0);
    forn(i, n) {
        assert(ans[i] % 2 == 0);
        ans[i] /= 2;
        ans[i] += 1;
    }
    forn(i, n) printf("%I64d ", ans[i]);
    puts("");
    return 0;
}