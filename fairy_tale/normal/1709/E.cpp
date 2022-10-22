#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t << 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

vector<int> g[maxn];
set<int> q[maxn];
int a[maxn], ans = 0;

int merge(int u, int v) {
    int flag = 0;
    if (q[u].size() < q[v].size()) swap(q[u], q[v]);
    for (auto e:q[v]) {
        if (q[u].count(e ^ a[u])) flag = 1;
    }
    for (auto e:q[v]) q[u].insert(e);
    return flag;
}

void dfs(int u, int fa, int d) {
    int dep = d ^ a[u], count = 0;
    q[u].insert(dep);
    for (auto v:g[u]) {
        if (v == fa) continue;
        dfs(v, u, dep);
        count += merge(u, v);
    }

    if (count) {
        ans++;
        q[u].clear();
    }
}

void solve()
{
    int n, u, v;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1, 0, 0);
    cout << ans << endl;
}

int main()
{
#ifdef FEIFEI
    //freopen("input.txt", "r", stdin);
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