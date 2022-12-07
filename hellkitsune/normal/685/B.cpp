#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, q;
vector<int> g[300005];
int d[300005];
int nx[300005], sz[300005];
int par[300005];

void dfs(int v) {
    int &res = d[v];
    if (res != v) res = par[res];
    while (nx[res] != -1 && 2 * sz[nx[res]] > sz[v]) {
        res = nx[res];
    }
    for (int to : g[v]) {
        if (nx[v] == to && res != v) {
            d[to] = res;
        } else {
            d[to] = to;
        }
        dfs(to);
    }
}

void calc(int v) {
    sz[v] = 1;
    for (int to : g[v]) {
        calc(to);
        sz[v] += sz[to];
    }
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d%d", &n, &q);
    for (int i = 1; i < n; ++i) {
        int j;
        scanf("%d", &j), --j;
        par[i] = j;
        g[j].pb(i);
    }
    calc(0);
    REP(i, n) {
        nx[i] = -1;
        for (int to : g[i]) if (nx[i] == -1 || sz[to] > sz[nx[i]]) {
            nx[i] = to;
        }
    }
    d[0] = 0;
    dfs(0);
    REP(i, q) {
        int v;
        scanf("%d", &v), --v;
        printf("%d\n", d[v] + 1);
    }
    return 0;
}