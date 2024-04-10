#include <bits/stdc++.h>

using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define mp make_pair
#define pb push_back
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<PII> g[100000];
int from[100000], to[100000];
char c[100000];
int col[100000];

bool ok;
int cnt0 = 0, cnt1 = 0;

void dfs(int v) {
    for (PII to : g[v]) if (col[to.first] == -1) {
        col[to.first] = col[v] ^ to.second;
        if (col[to.first] == 0) ++cnt0;
        else ++cnt1;
        dfs(to.first);
    } else if (col[to.first] != (col[v] ^ to.second)) {
        ok = false;
    }
}

void cl(int v) {
    col[v] = -1;
    for (PII to : g[v]) if (col[to.first] != -1) {
        cl(to.first);
    }
}

vector<int> ans;
bool found = false;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        scanf("%d%d %c", from + i, to + i, c + i), --from[i], --to[i];
    }
    REP(times, 2) {
        REP(i, n) g[i].clear();
        REP(i, m) if (c[i] == 'R') {
            g[from[i]].pb(mp(to[i], 0));
            g[to[i]].pb(mp(from[i], 0));
        } else {
            g[from[i]].pb(mp(to[i], 1));
            g[to[i]].pb(mp(from[i], 1));
        }
        ok = true;
        REP(i, n) col[i] = -1;
        REP(i, n) if (col[i] == -1) {
            col[i] = 0;
            cnt0 = 1, cnt1 = 0;
            dfs(i);
            if (!ok) break;
            if (cnt0 < cnt1) {
                cl(i);
                col[i] = 1;
                dfs(i);
            }
        }
        if (ok) {
            vector<int> cur;
            REP(i, n) if (col[i] == 1) {
                cur.pb(i + 1);
            }
            if (!found || cur.size() < ans.size()) {
                ans = cur;
            }
            found = true;
        }
        REP(i, m) c[i] = (c[i] == 'R') ? 'B' : 'R';
    }
    if (!found) {
        printf("-1\n");
    } else {
        printf("%d\n", (int)ans.size());
        for (int x : ans) printf("%d ", x);
        printf("\n");
    }
    return 0;
}