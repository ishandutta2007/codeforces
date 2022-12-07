#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, q;
int a[200][200], dx[10], dy[10];
char s[1000005];
int g[40000];
vector<int> rev[40000];
int num[40000];
int used[40000] = {};
vector<vector<int> > cycles;
vector<int> masks;
bool incyc[40000] = {};
int pos[10];

vector<int> cur;
int dfs(int v) {
    used[v] = 1;
    int to = g[v], ret = -1;
    if (used[to] == 0) {
        ret = dfs(to);
    } else if (used[to] == 1) {
        ret = to;
    }
    if (ret != -1) cur.pb(v);
    if (v == ret) ret = -1;
    used[v] = 2;
    return ret;
}

bool ok;
void go(int v, int bound) {
    if (bound >= 0 && s[bound] - '0' == num[v]) --bound;
    if (bound == -1) {
        ok = true;
        return;
    }
    for (int to : rev[v]) go(to, bound);
}

int main() {
    scanf("%d%d%d", &n, &m, &q);
    REP(i, n) {
        scanf("%s", s);
        REP(j, m) a[i][j] = s[j] - '0';
    }
    REP(i, 10) scanf("%d%d", dx + i, dy + i);
    REP(i, n) REP(j, m) {
        int ni = i + dx[a[i][j]];
        int nj = j + dy[a[i][j]];
        if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
            ni = i;
            nj = j;
        }
        g[i * m + j] = ni * m + nj;
        rev[ni * m + nj].pb(i * m + j);
    }
    REP(i, n) REP(j, m) num[i * m + j] = a[i][j];
    n *= m;
    REP(i, n) if (!used[i]) {
        dfs(i);
        if (!cur.empty()) {
            int mask = 0;
            for (int x : cur) {
                mask |= 1 << num[x];
                incyc[x] = true;
            }
            cycles.pb(cur);
            masks.pb(mask);
            cur.clear();
        }
    }
    REP(query, q) {
        scanf("%s", s);
        int len = strlen(s);
        REP(i, 10) pos[i] = -1;
        REP(i, len) pos[s[i] - '0'] = i;
        ok = false;
        REP(i, cycles.size()) {
            vector<int> &cycle = cycles[i];
            int &mask = masks[i];
            int bound = -1;
            REP(j, 10) if (!(mask & (1 << j))) {
                bound = max(bound, pos[j]);
            }
            if (bound == -1) {
                ok = true;
                break;
            }
            for (int v : cycle) for (int to : rev[v]) if (!incyc[to]) {
                go(to, bound);
            }
            if (ok) break;
        }
        if (ok) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}