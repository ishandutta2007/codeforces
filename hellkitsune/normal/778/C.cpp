#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, nodes;
int nx[700005][26];
vector<PII> tr[300005];
int sz[700005], h[700005];
int *pos[1000000];
int val[1000000];
int cnt = 0;

inline void change(int &x, int y) {
    pos[cnt] = &x;
    val[cnt] = x;
    x = y;
    ++cnt;
}

inline void rollback() {
    while (cnt) {
        --cnt;
        *(pos[cnt]) = val[cnt];
    }
    nodes = n;
}

void dfs(int v, int hh) {
    h[v] = hh;
    sz[v] = 1;
    forn(i, 26) if (nx[v][i]) {
        dfs(nx[v][i], hh + 1);
        sz[v] += sz[nx[v][i]];
    }
}

int res[300005];
int hh[300005];
PII p[26];
int pc = 0;
int tot;

void dfs2(int u, int v) {
    for (PII t : tr[v]) {
        if (nx[u][t.first]) {
            ++tot;
        } else {
            change(nx[u][t.first], nodes);
            ++nodes;
        }
        dfs2(nx[u][t.first], t.second);
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        char c;
        scanf("%d%d %c", &from, &to, &c), --from, --to;
        nx[from][c - 'a'] = to;
        tr[from].pb(mp(c - 'a', to));
    }
    dfs(0, 0);
    nodes = n;
    forn(i, n) {
        pc = 0;
        forn(j, 26) if (nx[i][j]) {
            p[pc++] = mp(-sz[nx[i][j]], nx[i][j]);
        }
        if (pc <= 1) {
            res[i] = pc;
            hh[h[i]] += res[i];
            continue;
        }
        sort(p, p + pc);
        int big = p[0].second;
        tot = 0;
        for (int z = 1; z < pc; ++z) {
            int cur = p[z].second;
            dfs2(big, cur);
        }
        res[i] = tot + pc;
        hh[h[i]] += res[i];
        rollback();
    }
    int best = 0, bestInd = 1;
    forn(i, n) if (hh[i] > best) {
        best = hh[i];
        bestInd = i + 1;
    }
    cout << n - best << endl << bestInd << endl;
    return 0;
}