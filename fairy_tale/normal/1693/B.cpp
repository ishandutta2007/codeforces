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
int l[maxn], r[maxn];
int ans;
LL dfs(int u)
{
    LL w = 0;
    for (auto v:g[u]) w += dfs(v);
    if (w < l[u]) {
        ans++;
        return r[u];
    } else return min(w, (LL)r[u]);
}

void solve()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 2; i <= n; i++) {
        cin >> x;
        g[x].push_back(i);
    }
    for (int i = 1; i <= n; i++) cin >> l[i] >> r[i];

    ans = 0;
    dfs(1);
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