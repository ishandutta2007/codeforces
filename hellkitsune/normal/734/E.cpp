#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int N = 200005;

int n;
int col[N];
vector<int> g[N], gg[N];
bool used[N] = {};
queue<PII> q;
vector<int> cmp;
int cnt = 1;

void dfs(int v) {
    used[v] = true;
    cmp.pb(v);
    for (int to : g[v]) if (!used[to] && col[to] == col[v]) {
        dfs(to);
    }
}

int dist[N];
int best;

void go(int v, int p) {
    if (p == -1) {
        dist[v] = 0;
    } else {
        dist[v] = dist[p] + 1;
    }
    if (best == -1 || dist[v] > dist[best]) {
        best = v;
    }
    for (int to : gg[v]) if (to != p) {
        go(to, v);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", col + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    q.push(mp(0, 0));
    while (!q.empty()) {
        int v = q.front().first;
        int nv = q.front().second;
        q.pop();
        cmp.clear();
        dfs(v);
        for (int x : cmp) {
            for (int to : g[x]) if (!used[to]) {
                q.push(mp(to, cnt));
                gg[nv].pb(cnt);
                gg[cnt].pb(nv);
                ++cnt;
            }
        }
    }
    memset(dist, 0, sizeof dist);
    best = -1;
    go(0, -1);
    int from = best;
    best = -1;
    memset(dist, 0, sizeof dist);
    go(from, -1);
    cout << (dist[best] + 1) / 2 << endl;
    return 0;
}