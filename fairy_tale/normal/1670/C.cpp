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
const int maxn = 1e5 + 5;

int mul(int x,int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int add(int x,int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int a[maxn], b[maxn], c[maxn], vis[maxn], sT;
vector<int> g[maxn];

void dfs(int u, int fa, int t)
{
    if (vis[u] == t) return;
    vis[u] = t;
    for (auto v:g[u]) {
        if (v == fa) continue;
        dfs(v, u, t);
    }
}

void solve()
{
    int n, m = 0;
    sT++;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) {
        if (c[i] == 0) {
            g[a[i]].push_back(b[i]);
            g[b[i]].push_back(a[i]);
        }
    }


    for (int i = 1; i <= n; i++) {
        if (c[i] != 0) {
            dfs(a[i], 0, sT);
            dfs(b[i], 0, sT);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (vis[a[i]] != sT && a[i] != b[i]) {
            dfs(a[i], 0, sT);
            m++;
        }
    }

    cout << powt(2, m) << endl;
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