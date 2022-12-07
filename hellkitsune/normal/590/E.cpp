#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MAX = 1e7 + 111;
int nx[MAX][2] = {}, term[MAX], link[MAX] = {}, tlink[MAX] = {}, par[MAX] = {}, q[MAX];
signed char pc[MAX];
int nodes = 2, root;
string s[750];
char buf[MAX];
int n;

void addString(int ind) {
    int pos = root;
    for (char c : s[ind]) {
        int val = c - 'a';
        if (!nx[pos][val]) {
            nx[pos][val] = nodes;
            par[nodes] = pos;
            pc[nodes++] = val;
        }
        pos = nx[pos][val];
    }
    term[pos] = ind;
}

void acBuild() {
    REP(i, 2) nx[0][i] = 1;
    root = 1;
    memset(term, -1, sizeof term);
    REP(i, n) addString(i);
    q[0] = root;
    for (int qh = 0, qt = 1; qh != qt; ++qh) {
        int v = q[qh];
        if (v != root) {
            int p = link[par[v]];
            int c = pc[v];
            while (!nx[p][c]) p = link[p];
            link[v] = nx[p][c];
            tlink[v] = term[link[v]] >= 0 ? link[v] : tlink[link[v]];
        }
        REP(i, 2) if (nx[v][i]) q[qt++] = nx[v][i];
    }
}

bool g[750][750] = {};
vector<int> gg[750];
int mt[750], fmt[750];
bool used[750], pused[750] = {};
vector<int> ans;

bool dfs(int v) {
    if (used[v]) return false;
    used[v] = true;
    for (int to : gg[v]) if (mt[to] == -1 || dfs(mt[to])) {
        mt[to] = v;
        return true;
    }
    return false;
}

void acGo(int ind) {
    int pos = root;
    for (char c : s[ind]) {
        int val = c - 'a';
        while (!nx[pos][val]) pos = link[pos];
        pos = nx[pos][val];
        for (int i = term[pos] >= 0 ? pos : tlink[pos]; i; i = tlink[i]) {
            if (term[i] == ind) continue;
            if (g[ind][term[i]]) break;
            g[ind][term[i]] = true;
        }
    }
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%s", buf), s[i] = string(buf);
    acBuild();
    REP(i, n) acGo(i);
    REP(k, n) REP(i, n) REP(j, n) {
        g[i][j] |= g[i][k] & g[k][j];
    }
    REP(i, n) REP(j, n) if (g[i][j]) {
        gg[i].pb(j);
    }
    REP(i, n) mt[i] = -1;
    REP(i, n) {
        for (int to : gg[i]) if (mt[to] == -1) {
            mt[to] = i;
            pused[i] = true;
            break;
        }
    }
    REP(i, n) if (!pused[i]) {
        REP(j, n) used[j] = false;
        dfs(i);
    }
    REP(i, n) fmt[i] = -1;
    REP(i, n) if (mt[i] != -1) fmt[mt[i]] = i;
    REP(i, n) if (mt[i] == -1) ans.pb(i);
    bool done = false;
    while (!done) {
        done = true;
        for (int &x : ans) for (int y : ans) if (y != x) while (g[x][y]) {
            x = fmt[x];
            done = false;
        }
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x + 1);
    printf("\n");
    return 0;
}