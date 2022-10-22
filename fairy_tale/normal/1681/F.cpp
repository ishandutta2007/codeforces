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
typedef pair<LL, int> PL;

const int maxn = 5e5 + 5;
const int mod = 998244353;

vector<P> g[maxn];
int a[maxn], b[maxn], w[maxn], pa[maxn], sz[maxn];

void dfs(int u, int fa, int val) {
	int oldW = w[val];
	b[u] = pa[val];
	pa[val] = u;
	sz[u] = 1;
	
	for (auto e:g[u]) {
		int v = e.fi;
		if (v == fa) continue;	
		dfs(v, u, e.se);
		sz[u] += sz[v];
	}
	
	a[u] = sz[u] - (w[val] - oldW);
	w[val] = oldW + sz[u];
	pa[val] = b[u];
	if (b[u] == 0) b[u] = -val;
}

void solve()
{
    int n, u, v, x;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> x;
        g[u].push_back(P(v, x));
        g[v].push_back(P(u, x));
    }

	dfs(1, 0, 0);
	LL ans = 0;
	for (int i = 2; i <= n; i++) {
	    if (b[i] > 0) b[i] = a[b[i]];
	    else b[i] = n - w[-b[i]];
	}
	for (int i = 2; i <= n; i++) ans += 1LL * a[i] * b[i];
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
    //cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}