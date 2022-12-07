#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
vector<int> g[1000005];
int cnt = 0;
bool haveEdges;
bool used[1000005] = {};
int same = 0;
int dif[1000005] = {};

void dfs(int v) {
    used[v] = true;
    haveEdges |= !g[v].empty();
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
        if (from == to) {
            ++same;
        } else {
            ++dif[from];
            ++dif[to];
        }
    }
    forn(i, n) if (!used[i]) {
        haveEdges = false;
        dfs(i);
        if (haveEdges) {
            ++cnt;
        }
    }
    if (cnt > 1) {
        cout << 0 << endl;
        return 0;
    }
    LL ans = (LL)same * (same - 1) / 2;
    LL ans2 = 0;
    forn(i, n) {
        ans += (LL)dif[i] * (dif[i] - 1) / 2;
        ans2 += (LL)same * dif[i];
    }
    ans += ans2 / 2;
    cout << ans << endl;
    return 0;
}