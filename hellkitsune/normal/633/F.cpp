#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

int n, a[100000];
vector<PII> g[100000];
LL m1[200000], m2[200000], ans[200000], s[200000], t[200000];

void dfs(int v, int p, int ind) {
    if (ans[ind] != -1) return;
    LL &mx = m1[ind] = 0;
    LL &mx2 = m2[ind] = 0;
    LL &best = ans[ind] = 0;
    for (PII e : g[v]) if (e.first != p) {
        dfs(e.first, v, e.second);
        LL val = m1[e.second] + a[e.first];
        if (val > mx) {
            mx2 = mx;
            mx = val;
        } else {
            mx2 = max(mx2, val);
        }
        best = max(best, ans[e.second]);
    }
    best = max(best, mx + mx2 + a[v]);
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(mp(to, 2 * i));
        g[to].pb(mp(from, 2 * i + 1));
        s[2 * i] = from;
        t[2 * i] = to;
        s[2 * i + 1] = to;
        t[2 * i + 1] = from;
    }
    REP(i, 2 * n - 2) ans[i] = -1;
    REP(i, 2 * n - 2) if (ans[i] == -1) {
        dfs(t[i], s[i], i);
    }
    LL best = 0;
    REP(i, n - 1) best = max(best, ans[2 * i] + ans[2 * i + 1]);
    cout << best << endl;
    return 0;
}