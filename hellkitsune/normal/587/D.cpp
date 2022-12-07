#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

struct E {
    int to, col, time, ind;
    E(int to, int col, int time, int ind) : to(to), col(col), time(time), ind(ind) {}
};

int n, m, cnt;
vector<E> g[50000];
int a[50000], b[50000], c[50000], d[50000], t[50000];
map<int, PII> colInd;
const int INF = 1e9 + 99;
vector<int> sat[311111], rev[311111], tmp[311111], ord;
bool used[311111];
int cmp[311111], curCmp;

void dfs1(int v) {
    used[v] = true;
    for (int to : sat[v]) if (!used[to]) {
        dfs1(to);
    }
    ord.pb(v);
}

void dfs2(int v) {
    cmp[v] = curCmp;
    for (int to : rev[v]) if (cmp[to] == -1) {
        dfs2(to);
    }
}

bool solve(int bound) {
    REP(i, cnt << 1) sat[i] = tmp[i];
    REP(i, m) if (t[i] > bound) {
        sat[i << 1].pb((i << 1) | 1);
    }
    REP(i, cnt << 1) rev[i].clear();
    REP(i, cnt << 1) for (int to : sat[i]) {
        rev[to].pb(i);
    }
    REP(i, cnt << 1) used[i] = false;
    ord.clear();
    REP(i, cnt << 1) if (!used[i]) {
        dfs1(i);
    }
    reverse(ord.begin(), ord.end());
    REP(i, cnt << 1) cmp[i] = -1;
    curCmp = 0;
    for (int i : ord) if (cmp[i] == -1) {
        dfs2(i);
        ++curCmp;
    }
    REP(i, cnt) if (cmp[i << 1] == cmp[(i << 1) | 1]) {
        return false;
    }
    return true;
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    REP(i, m) {
        int from, to, c, tt;
        scanf("%d%d%d%d", &from, &to, &c, &tt), --from, --to;
        g[from].pb(E(to, c, tt, i));
        g[to].pb(E(from, c, tt, i));
        t[i] = tt;
    }
    REP(i, n) {
        a[i] = -1;
        for (E e : g[i]) {
            auto it = colInd.find(e.col);
            if (it != colInd.end()) {
                if (a[i] != -1) {
                    printf("No\n");
                    return 0;
                }
                a[i] = it->second.first;
                b[i] = e.ind;
                c[i] = it->second.second;
                d[i] = e.time;
            } else {
                colInd[e.col] = mp(e.ind, e.time);
            }
        }
        colInd.clear();
    }
    int lo = 0, hi = 0, mid;
    REP(i, n) if (a[i] != -1) {
        lo = max(lo, min(c[i], d[i]));
        hi = max(hi, max(c[i], d[i]));
    }
    if (hi == 0) {
        printf("Yes\n0 0\n");
        return 0;
    }
    cnt = m;
    REP(i, n) if ((int)g[i].size() > 1) {
        REP(j, (int)g[i].size() - 1) {
            tmp[g[i][j].ind << 1].pb((cnt + j) << 1);
            tmp[((cnt + j) << 1) | 1].pb((g[i][j].ind << 1) | 1);
        }
        REP(j, (int)g[i].size() - 2) {
            tmp[(cnt + j) << 1].pb((cnt + j + 1) << 1);
            tmp[((cnt + j + 1) << 1) | 1].pb(((cnt + j) << 1) | 1);
        }
        for (int j = 1; j < (int)g[i].size(); ++j) {
            tmp[g[i][j].ind << 1].pb(((cnt + j - 1) << 1) | 1);
            tmp[(cnt + j - 1) << 1].pb((g[i][j].ind << 1) | 1);
        }
        cnt += (int)g[i].size() - 1;
    }
    REP(i, n) if (a[i] != -1) {
        tmp[(a[i] << 1) | 1].pb(b[i] << 1);
        tmp[(b[i] << 1) | 1].pb(a[i] << 1);
    }
    while (lo < hi) {
        mid = (lo + hi) >> 1;
        if (solve(mid)) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    if (solve(lo)) {
        printf("Yes\n");
        vector<int> ans;
        REP(i, m) if (cmp[(i << 1) | 1] < cmp[i << 1]) {
            ans.pb(i);
        }
        printf("%d %d\n", lo, (int)ans.size());
        for (int x : ans) printf("%d ", x + 1);
        printf("\n");
    } else {
        printf("No\n");
    }
    return 0;
}