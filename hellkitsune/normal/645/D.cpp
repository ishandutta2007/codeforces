#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
bool vis[100000];
vector<int> ord;
int rev[100000];
int from[100000], to[100000];

void dfs(int v) {
    vis[v] = true;
    for (int to : g[v]) if (!vis[to]) {
        dfs(to);
    }
    ord.pb(v);
}

int main() {
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d", from + i, to + i), --from[i], --to[i];
        g[from[i]].pb(to[i]);
    }
    REP(i, n) if (!vis[i]) {
        dfs(i);
    }
    REP(i, n) rev[ord[i]] = i;
    int cnt = 0, mx = -1;
    REP(i, m) if (abs(rev[from[i]] - rev[to[i]]) == 1) {
        ++cnt;
        mx = i + 1;
    }
    if (cnt != n - 1) mx = -1;
    printf("%d\n", mx);
    return 0;
}