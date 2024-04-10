#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<PII> g[200000];
int col[200000];
vector<int> plan[200000];

void dfs(int v, int p, int bad) {
    int cur = 0;
    for (PII to : g[v]) if (to.first != p) {
        if (cur == bad) ++cur;
        col[to.second] = cur;
        dfs(to.first, v, cur);
        ++cur;
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, i));
        g[to].pb(mp(from, i));
    }
    dfs(0, -1, -1);
    REP(i, n - 1) plan[col[i]].pb(i);
    int mx = 0;
    REP(i, n - 1) mx = max(mx, col[i]);
    printf("%d\n", mx + 1);
    REP(i, mx + 1) {
        printf("%d", (int)plan[i].size());
        for (int x : plan[i]) {
            printf(" %d", x + 1);
        }
        printf("\n");
    }
    return 0;
}