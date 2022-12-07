#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[200005];
bool used[200005];
vector<int> cm;

void dfs(int v) {
    cm.pb(v);
    used[v] = true;
    for (int to : g[v]) if (!used[to]) {
        dfs(to);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    int ans = 0;
    forn(i, n) if (!used[i]) {
        cm.clear();
        dfs(i);
        bool ok = true;
        for (int x : cm) {
            if ((int)g[x].size() != 2) {
                ok = false;
            }
        }
        ans += ok;
    }
    cout << ans << endl;
    return 0;
}