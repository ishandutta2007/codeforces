#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, x, y;
vector<int> g[200000];
int d[2][200000], o[200000];

void dfs(int v, int p) {
    int a = 0, b = 0, c = 0, na, nb, nc;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        na = a + d[0][to] + 1;
        nb = min(a + d[1][to], b + d[0][to] + 1);
        nc = min(b + d[1][to], c + d[0][to] + 1);
        a = na;
        b = nb;
        c = nc;
    }
    d[1][v] = min(a, b);
    d[0][v] = min(d[1][v], c);
}

int main() {
    scanf("%d%d%d", &n, &x, &y);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    if (x <= y) {
        dfs(0, -1);
        int cnt = d[0][0];
        cout << (LL)cnt * y + (n - 1 - cnt) * (LL)x << endl;
        return 0;
    } else {
        bool ok = true;
        REP(i, n) if ((int)g[i].size() == n - 1) ok = false;
        if (ok) cout << (LL)(n - 1) * y << endl;
        else cout << (LL)(n - 2) * y + x << endl;
    }
    return 0;
}