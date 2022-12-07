#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[200005];
int par[200005], w[200005], p[200005], can[200005];
int dep[200005];

struct Cmp {
    inline bool operator()(const int &lhs, const int &rhs) const {
        if (dep[lhs] != dep[rhs]) return dep[lhs] > dep[rhs];
        return lhs < rhs;
    }
};

set<int, Cmp> tmp[200005];
set<int, Cmp> *ch[200005];

set<int, Cmp>* merge(set<int, Cmp> *a, set<int, Cmp> *b) {
    if (a->size() < b->size()) {
        swap(a, b);
    }
    for (int x : *b) {
        a->insert(x);
    }
    return a;
}

LL solve(int v) {
    if (v == 0) {
        dep[v] = 0;
    } else {
        dep[v] = dep[par[v]] + 1;
    }
    LL sum = 0;
    for (int to : g[v]) {
        sum += solve(to);
    }
    if (v == 0) {
        return sum;
    }
    if (sum > p[v]) {
        cout << -1 << endl;
        exit(0);
    }
    can[v] = min(w[v] - 1, int(p[v] - sum));
    return sum + w[v] - can[v];
}

LL dfs(int v) {
    for (int to : g[v]) {
        ch[v]->insert(to);
    }
    LL sum = 0;
    for (int to : g[v]) {
        sum += dfs(to);
        ch[v] = merge(ch[v], ch[to]);
    }
    if (v == 0) {
        return sum;
    }
    set<int, Cmp> &cur = *(ch[v]);
    while (!cur.empty() && sum > p[v]) {
        int u = *cur.begin();
        if (sum - p[v] >= can[u]) {
            cur.erase(cur.begin());
            sum -= can[u];
            p[u] -= can[u];
            w[u] -= can[u];
            can[u] = 0;
        } else {
            w[u] -= sum - p[v];
            p[u] -= sum - p[v];
            can[u] -= sum - p[v];
            sum = p[v];
        }
    }
    if (sum > p[v]) {
        cout << -1 << endl;
        exit(0);
    }
    return sum + w[v];
}

vector<int> ord;

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to, ww, pp;
        scanf("%d%d%d%d", &from, &to, &ww, &pp), --from, --to;
        g[from].pb(to);
        par[to] = from;
        w[to] = ww;
        p[to] = pp;
        ord.pb(to);
    }
    forn(i, n) {
        ch[i] = &tmp[i];
    }
    solve(0);
    dfs(0);
    cout << n << endl;
    for (int x : ord) {
        printf("%d %d %d %d\n", par[x] + 1, x + 1, w[x], p[x]);
    }
    return 0;
}