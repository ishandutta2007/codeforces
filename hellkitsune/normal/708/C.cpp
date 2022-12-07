#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, mx;
vector<int> g[400005];
int sz[400005], can[400005];
int ans[400005] = {};

void dfs(int v, int p) {
    sz[v] = 1;
    can[v] = 1;
    for (int to : g[v]) if (to != p) {
        dfs(to, v);
        sz[v] += sz[to];
        can[v] = max(can[v], can[to]);
        if (sz[to] <= mx) {
            can[v] = max(can[v], sz[to]);
        }
    }
}

void solve(int v, int p, int upcan) {
    int upsz = n - sz[v];
    ans[v] = (upsz - upcan <= mx);
    vector<int> pref, suf;
    for (int to : g[v]) if (to != p) {
        int ncan = can[to];
        if (sz[to] <= mx) {
            ncan = max(ncan, sz[to]);
        }
        pref.pb(ncan);
        suf.pb(ncan);
    }
    for (int i = 1; i < (int)pref.size(); ++i) {
        pref[i] = max(pref[i], pref[i - 1]);
    }
    for (int i = (int)pref.size() - 2; i >= 0; --i) {
        suf[i] = max(suf[i], suf[i + 1]);
    }
    int curInd = 0;
    for (int to : g[v]) if (to != p) {
        if (sz[to] - can[to] > mx) {
            ans[v] = false;
        }
        int nupcan = upcan;
        if (curInd != 0) {
            nupcan = max(nupcan, pref[curInd - 1]);
        }
        if (curInd != (int)suf.size() - 1) {
            nupcan = max(nupcan, suf[curInd + 1]);
        }
        int rem = n - sz[to];
        if (rem <= mx) {
            nupcan = max(nupcan, rem);
        }
        solve(to, v, nupcan);
        ++curInd;
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    mx = n / 2;
    dfs(0, -1);
    solve(0, -1, 0);
    forn(i, n) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}