#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MOD = int(1e9) + 7;

int n;
int a[200005];
vector<int> g[200005];
int col[200005];
int cnt[200005][2];
int tot[2];

vector<PII> vec[200005];
void solve(int v) {
    cnt[v][0] = cnt[v][1] = 0;
    cnt[v][col[v]] = 1;
    for (int to : g[v]) if (cnt[to][0] == -1) {
        solve(to);
        cnt[v][0] += cnt[to][0];
        cnt[v][1] += cnt[to][1];
        vec[v].pb(mp(cnt[to][0], cnt[to][1]));
    }
    vec[v].pb(mp(tot[0] - cnt[v][0], tot[1] - cnt[v][1]));
}

void dfs(int v) {
    ++tot[col[v]];
    for (int to : g[v]) if (col[to] == -1) {
        col[to] = col[v] ^ 1;
        dfs(to);
    }
}

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n - 1) {
        int from, to;
        scanf("%d%d", &from, &to), --from, --to;
        g[from].pb(to);
        g[to].pb(from);
    }
    memset(col, -1, sizeof col);
    col[0] = 0;
    dfs(0);
    memset(cnt, -1, sizeof cnt);
    solve(0);

    int ans = 0;
    forn(v, n) {
        int sum = n;
        for (PII p : vec[v]) {
            if (col[v] == 1) swap(p.first, p.second);
            int rem = n - p.first - p.second;
            sum = (sum + (LL)(p.first - p.second) * rem) % MOD;
        }
        ans = (ans + (LL)sum * a[v]) % MOD;
    }
    if (ans < 0) ans += MOD;
    cout << ans << endl;
    return 0;
}