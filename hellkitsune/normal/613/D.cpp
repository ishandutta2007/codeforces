#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
vector<int> g[100000], gg[100000];
int tin[100000], tout[100000], dep[100000], timer = 0;
int par[17][100000];
int isLong[100000];
int gpar[100000];

void dfs(int v, int p) {
    tin[v] = timer++;
    if (p == -1) dep[v] = 0;
    else dep[v] = dep[p] + 1;
    par[0][v] = p;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
    }
    tout[v] = timer++;
}

inline bool isParent(int x, int p) {
    return tin[p] <= tin[x] && tout[p] >= tout[x];
}

int k, a[200000];
bool imp[100000] = {};

inline bool cmp(const int &lhs, const int &rhs) {
    return tin[lhs] < tin[rhs];
}

int lca(int x, int y) {
    if (dep[x] < dep[y]) swap(x, y);
    if (isParent(x, y)) return y;
    for (int i = 16; i >= 0; --i) {
        if (par[i][y] != -1 && !isParent(x, par[i][y])) {
            y = par[i][y];
        }
    }
    return par[0][y];
}

stack<int> st;
int d[2][100000];
const int INF = 1e9;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    REP(i, 16) REP(j, n) if (par[i][j] == -1) {
        par[i + 1][j] = -1;
    } else {
        par[i + 1][j] = par[i][par[i][j]];
    }
    scanf("%d", &q);
    REP(qq, q) {
        scanf("%d", &k);
        REP(i, k) scanf("%d", a + i), --a[i], imp[a[i]] = true;
        sort(a, a + k, cmp);
        REP(i, k - 1) a[k + i] = lca(a[i], a[i + 1]);
        sort(a, a + (2 * k - 1), cmp);
        k = unique(a, a + (2 * k - 1)) - a;
        st.push(0);
        for (int i = 1; i < k; ++i) {
            while (!st.empty() && !isParent(a[i], a[st.top()])) st.pop();
            assert(!st.empty());
            gg[st.top()].pb(i);
            gpar[i] = st.top();
            st.push(i);
        }
        for (int i = k - 1; i > 0; --i) isLong[i] = par[0][a[i]] != a[gpar[i]];
        isLong[0] = 0;
        bool na = false;
        for (int i = k - 1; i >= 0; --i) {
            int sum0 = 0, sum1 = 0, best1, bad = 0;
            for (int to : gg[i]) if (d[0][to] == INF) ++bad;
            for (int to : gg[i]) {
                sum0 = min(INF, sum0 + d[0][to]);
                sum1 = min(INF, sum1 + min(d[0][to], d[1][to]));
            }
            if (bad == 1) {
                best1 = 0;
                for (int to : gg[i]) if (d[0][to] == INF) best1 += d[1][to];
                else best1 += d[0][to];
            } else if (bad == 0) {
                best1 = sum0;
                for (int to : gg[i]) best1 = min(best1, sum0 - d[0][to] + d[1][to]);
            }
            if (bad && imp[a[i]]) na = true;
            if (na) break;
            if (imp[a[i]]) {
                d[0][i] = INF;
                d[1][i] = sum0;
            } else {
                if (bad) d[0][i] = min(INF, sum1 + 1);
                else d[0][i] = min(sum1 + 1, sum0);
                if (bad < 2) d[1][i] = best1;
                else d[1][i] = INF;
            }
            if (isLong[i]) {
                d[0][i] = min(d[0][i], d[1][i] + 1);
            }
        }
        if (na || min(d[0][0], d[1][0]) == INF) printf("-1\n");
        else printf("%d\n", min(d[0][0], d[1][0]));
        REP(i, k) imp[a[i]] = false;
        REP(i, k) gg[i].clear();
    }
    return 0;
}