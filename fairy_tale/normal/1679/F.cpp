#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define endl '\n'
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 1e6 + 5;
const int mod  = 998244353;

void upd(int &x, int y) {
    x += y;
    if(x >= mod) x -= mod;
}

int mask[11], sp[11];
int dp[2][1024];
void solve()
{
    int n, m, u, v, w;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        mask[u] |= 1 << v;
        mask[v] |= 1 << u;
    }

    for (int i = 0; i < 10; i++) sp[i] = (1 << i) - 1;

    u = 0;
    dp[u][0] = 1;
    for (int i = 0; i < n; i++) {
        v = u ^ 1;
        memset(dp[v], 0, sizeof(dp[v]));
        for (int j = 0; j < 1024; j++) {
            if (!dp[u][j]) continue;
            for (int x = 0; x < 10; x++) {
                w = j & mask[x];
                if (!(w & sp[x])) upd(dp[v][w | (1 << x)], dp[u][j]);
            }
        }

        u ^= 1;
    }

    int ans = 0;
    for (int i = 0; i < 1024; i++) upd(ans, dp[u][i]);
    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}