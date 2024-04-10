#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int mod = 998244353;
const int maxn = 2e5 + 5;

vector<int> g[maxn];
int a[maxn], b[maxn], vis[maxn], sT;

int dfs(int u, int fa)
{
    if (vis[u] == sT) return 0;
    vis[u] = sT;
    for (auto v:g[u]) {
        if (v == fa) continue;
        return dfs(v, u) + 1;
    }
    return 1;
}

void solve()
{
    int n, m = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) g[i].clear();

    sT++;
    for (int i = 1; i <= n; i++) {
        if (a[i] == b[i]) vis[a[i]] = sT;
        else {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] != sT) {
            int len = dfs(a[i], 0);
            //cout << a[i] << " " << len << endl;
            m += len / 2;
        }
    }

    LL ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += (n - i + 1 - i) * 2;
    }
    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}