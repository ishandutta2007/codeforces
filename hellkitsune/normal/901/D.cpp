#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[100000];
LL c[100000];
LL w[100000];
int uu[100000], vv[100000];
int col[100000];
int st[100000], sz = 0;
vector<int> cyc;
int cycv = 0;
bool flag = true;

bool dfs(int v, int co) {
    st[sz++] = v;
    col[v] = co;
    for (int e : g[v]) {
        int to = (uu[e] == v ? vv[e] : uu[e]);
        if (col[to] == -1) {
            if (dfs(to, co ^ 1)) {
                if (flag) {
                    cyc.pb(e);
                    if (v == cycv) {
                        flag = false;
                    }
                }
                return true;
            }
        } else if (col[to] == col[v] && cyc.empty()) {
            cyc.pb(e);
            cycv = to;
            flag = true;
            return true;
        }
    }
    --sz;
    return false;
}

bool used[100000] = {};

void solve(int v) {
    used[v] = true;
    for (int e : g[v]) {
        int to = (uu[e] == v ? vv[e] : uu[e]);
        if (used[to]) {
            continue;
        }
        solve(to);
        w[e] = -c[to];

        c[to] += w[e];
        c[v] += w[e];
    }
}

int main() {
//    freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    forn(i, n) scanf("%I64d", c + i), c[i] *= -1;
    forn(i, m) {
        scanf("%d%d", uu + i, vv + i), --uu[i], --vv[i];
        g[uu[i]].pb(i);
        g[vv[i]].pb(i);
    }
    memset(col, -1, sizeof col);
    dfs(0, 0);
    solve(cycv);
    if (c[cycv] != 0) {
        if (cyc.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        LL need = -c[cycv] / 2;
        for (int x : cyc) {
            w[x] += need;
            need *= -1;
        }
    }
    cout << "YES" << endl;
    forn(i, m) printf("%I64d\n", w[i]);
    return 0;
}