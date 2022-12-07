#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];
vector<PII> g[100000];
int ans;

void dfs(int v, int p, LL sum) {
    if (a[v] < sum) {
        return;
    }
    --ans;
    for (PII to : g[v]) if (to.first != p) {
        dfs(to.first, v, max(0ll, sum + to.second));
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n - 1) {
        int from = i + 1, to, w;
        scanf("%d%d", &to, &w), --to;
        g[from].pb(mp(to, w));
        g[to].pb(mp(from, w));
    }
    ans = n;
    dfs(0, -1, 0);
    cout << ans << endl;
    return 0;
}