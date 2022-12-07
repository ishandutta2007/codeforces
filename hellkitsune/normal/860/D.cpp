#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<PII> g[200000];
bool e[200000];
bool used[200000];
vector<pair<PII, int> > ans;

bool dfs(int v, int par) {
    int t = -1;
    used[v] = true;
    for (PII to : g[v]) if (!e[to.second]) {
        e[to.second] = true;
        if (!used[to.first]) {
            if (dfs(to.first, v)) {
                if (t == -1) {
                    t = to.first;
                } else {
                    ans.pb(mp(mp(t, v), to.first));
                    t = -1;
                }
            }
        } else {
            if (t == -1) {
                t = to.first;
            } else {
                ans.pb(mp(mp(t, v), to.first));
                t = -1;
            }
        }
    }
    if (par != -1 && t != -1) {
        ans.pb(mp(mp(t, v), par));
        return false;
    }
    return true;
}

int main() {
    scanf("%d%d", &n, &m);
    forn(i, m) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, i));
        g[to].pb(mp(from, i));
    }
    forn(i, n) if (!used[i]) {
        dfs(i, -1);
    }
    printf("%d\n", (int)ans.size());
    for (auto p : ans) {
        printf("%d %d %d\n", p.first.first + 1, p.first.second + 1, p.second + 1);
    }
    return 0;
}