#include <bits/stdc++.h>
using namespace std;

const int maxn = 2010;
int n, tim, tp, tot, st[maxn], dfn[maxn], low[maxn], bel[maxn];
string fir[maxn], sec[maxn], foo[maxn], bar[maxn];
vector<int> G[maxn];

void tarjan(int v) {
    dfn[v] = low[v] = ++tim, st[++tp] = v;
    for (int u : G[v]) {
        if (!dfn[u]) tarjan(u), low[v] = min(low[v], low[u]);
        else if (!bel[u]) low[v] = min(low[v], dfn[u]);
    }
    if (dfn[v] == low[v]) {
        tot++;
        while (1) {
            int u = st[tp--]; bel[u] = tot;
            if (u == v) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> fir[i] >> sec[i];
        foo[i] = fir[i].substr(0, 3);
        bar[i] = fir[i].substr(0, 2) + sec[i].substr(0, 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) if (i ^ j) {
            if (foo[i] == foo[j]) G[i].push_back(j + n);
            if (foo[i] == bar[j]) G[i].push_back(j);
            if (bar[i] == foo[j]) G[i + n].push_back(j + n);
            if (bar[i] == bar[j]) G[i + n].push_back(j);
            if (foo[i] == foo[j]) G[i + n].push_back(j + n);
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; i++) {
        if (bel[i] == bel[i + n]) cout << "NO\n", exit(0);
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        if (bel[i] < bel[i + n]) cout << foo[i] << '\n';
        else cout << bar[i] << "\n";
    }
    return 0;
}