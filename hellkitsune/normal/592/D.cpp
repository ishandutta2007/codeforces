#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[133333];
int d[133333], e[133333] = {};
int deg[133333] = {};
bool bad[133333] = {};
queue<int> q;

int best, prevBest;
void dfs(int v, int p) {
    if (p == -1) d[v] = 0;
    else d[v] = d[p] + 1;
    if (d[v] > d[best] || (d[v] == d[best] && v < best)) best = v;
    for (int to : g[v]) if (to != p && !bad[to]) {
        dfs(to, v);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
        ++deg[from];
        ++deg[to];
    }
    REP(i, m) {
        int x;
        scanf("%d", &x), --x;
        e[x] = 1;
    }
    REP(i, n) if (deg[i] == 1 && e[i] == 0) {
        q.push(i);
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        bad[v] = true;
        for (int to : g[v]) if (--deg[to] == 1 && e[to] == 0) {
            q.push(to);
        }
    }
    int ans = -2;
    REP(i, n) if (!bad[i]) ans += 2;
    best = 0;
    while (bad[best]) ++best;
    dfs(best, -1);
    prevBest = best;
    dfs(best, -1);
    ans -= d[best];
    best = min(best, prevBest);
    printf("%d\n%d\n", best + 1, ans);
    return 0;
}