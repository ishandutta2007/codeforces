#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[5000], rev[5000];
bool used[5000];
vector<int> ord;
bool curcm[5000];
vector<int> cm;

void dfs1(int v) {
    used[v] = true;
    for (int to : g[v]) if (!used[to]) {
        dfs1(to);
    }
    ord.pb(v);
}

void dfs2(int v) {
    used[v] = true;
    cm.pb(v);
    curcm[v] = true;
    for (int to : rev[v]) if (!used[to]) {
        dfs2(to);
    }
}

int dist[5000][5000];
int q[5000];

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        rev[to].pb(from);
    }
    memset(dist, -1, sizeof dist);
    REP(i, n) {
        int (&d)[5000] = dist[i];
        d[i] = 0;
        q[0] = i;
        for (int qh = 0, qt = 1; qh < qt; ++qh) {
            int v = q[qh];
            for (int to : g[v]) if (d[to] == -1) {
                d[to] = d[v] + 1;
                q[qt++] = to;
            }
        }
    }
    REP(i, n) used[i] = false;
    REP(i, n) if (!used[i]) {
        dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    REP(i, n) used[i] = false;
    int ans = n;
    for (int v : ord) if (!used[v]) {
        cm.clear();
        REP(i, n) curcm[i] = false;
        dfs2(v);
        bool ok = false;
        for (int x : cm) {
            for (int y : g[x]) if (!curcm[y]) {
                ok = true;
                break;
            }
            if (ok) break;
        }
        if (!ok && (int)cm.size() > 1) {
            ++ans;
            int z = 12341234;
            for (int x : cm) for (int from : rev[x]) if (dist[x][from] != -1) {
                z = min(z, dist[x][from] + 1);
            }
            ans += z * 998;
        }
    }
    printf("%d\n", ans);
    return 0;
}