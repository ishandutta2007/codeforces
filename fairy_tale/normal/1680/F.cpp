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
const int mod  = 1e9 + 7;

vector<P> g[maxn];
P edge[maxn];
int d[maxn], cnt[maxn], odd;
int f[maxn], sp[maxn];

void dfs(int u, int fa, int dep)
{
    d[u] = dep;
    for (auto e:g[u]) {
        int v = e.fi;
        if (v == fa) continue;
        if (d[v]) {
            if (d[v] > d[u]) continue;
            if ((d[u] - d[v] + 1) & 1) { // odd
                odd++;
                cnt[e.se]++;
                f[u]++;
                f[v]--;
            } else { // even
                sp[u]++;
                sp[v]--;
            }
            continue;
        }

        dfs(v, u, dep + 1);
        if (!sp[v]) cnt[e.se] = f[v];
        f[u] += f[v];
        sp[u] += sp[v];
    }
}

void dfs2(int u, int fa)
{
    for (auto e:g[u]) {
        if (f[e.fi] != -1) continue;
        f[e.fi] = f[u] ^ 1;
        dfs2(e.fi, u);
    }
}

void solve()
{
    int n, m, u, v, fg = 1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) g[i].clear();
    for (int i = 1; i <= n; i++) d[i] = 0;
    for (int i = 1; i <= n; i++) f[i] = 0;
    for (int i = 1; i <= n; i++) sp[i] = 0;

    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u].push_back(P(v, i));
        g[v].push_back(P(u, i));
        edge[i] = P(u, v);
    }

    for (int i = 0; i < m; i++) cnt[i] = 0;
    odd = 0;
    dfs(1, 0, 1);
    //cout<<odd<<endl;
    if (odd == 0) {
        cout << "YES" << endl;
        for (int i = 1; i <= n; i++) f[i] = -1;
        f[1] = 1;
        dfs2(1, 0);
        for (int i = 1; i <= n; i++) cout << f[i];
        cout << endl;
        return;
    }


    for (int i = 0; i < m; i++) {
        //cout << i << " " << cnt[i] << endl;
        if (cnt[i] == odd) {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) f[i] = -1;
            f[edge[i].fi] = f[edge[i].se] = 1;
            dfs2(edge[i].fi, edge[i].se);
            dfs2(edge[i].se, edge[i].fi);
            for (int i = 1; i <= n; i++) cout << f[i];
            cout << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("input.txt", "r", stdin);
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