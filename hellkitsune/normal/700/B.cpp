#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
vector<int> g[200000];
bool uni[200000] = {};
int sz[200000], dep[200000];

void dfs(int v, int p) {
    sz[v] = uni[v];
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        sz[v] += sz[to];
    }
}

LL ans = 0;

void dfs2(int v, int p) {
    if (p == -1) {
        dep[v] = 0;
    } else {
        dep[v] = dep[p] + 1;
    }
    if (uni[v]) {
        ans += dep[v];
    }
    for (int to : g[v]) if (to != p) {
        dfs2(to, v);
    }
}

int main() {
    scanf("%d%d", &n, &k);
    k *= 2;
    REP(i, k) {
        int x;
        scanf("%d", &x), --x;
        uni[x] = true;
    }
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1);
    int root = 0;
    int p = -1;
    while (true) {
        bool done = true;
        for (int to : g[root]) if (to != p && sz[to] * 2 > k) {
            p = root;
            root = to;
            done = false;
            break;
        }
        if (done) break;
    }
    dfs2(root, -1);
    cout << ans << endl;
    return 0;
}