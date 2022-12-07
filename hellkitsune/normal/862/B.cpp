#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> g[100000];
int a[2];

void dfs(int v, int par, int x) {
    ++a[x];
    for (int to : g[v]) if (to != par) {
        dfs(to, v, x ^ 1);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    dfs(0, -1, 0);
    LL ans = (LL)a[0] * a[1];
    ans -= n - 1;
    cout << ans << endl;
    return 0;
}