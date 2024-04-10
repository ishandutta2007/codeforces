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

const int mod = 1e9 + 7;
const int maxn = 3e5 + 5;


vector<P> g[maxn];
int idx, a[maxn], b[maxn];
int dfs(int u, int fa, int n, int fp)
{
    int x = idx++;
    for (auto e:g[u]) {
        if (e.fi == fa) continue;
        b[e.se] = dfs(e.fi, u, n, fp ^ 1);
    }
    if (fp) {
        a[u] = x + n;
        return x;
    } else {
        a[u] = x;
        return x + n;
    }
}


void solve()
{
    int p, n, u, v;
    cin >> p;
    n = 1 << p;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i < n; i++) {
        cin >> u >> v;
        g[u].push_back(P(v, i));
        g[v].push_back(P(u, i));
    }

    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 1) {
            idx = 0;
            dfs(i, 0, n, 1);
            cout << i << endl;
            break;
        }
    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i < n; i++) cout << b[i] << " ";
    cout << endl;
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