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

const int maxn = 2e5 + 5;
const int mod = 998244353;

int a[maxn], vis[maxn], du[maxn];
vector<int> g[maxn], gd[maxn];

void solve()
{
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    map<P, int> q;
    fill(du, du + n + 1, 0);
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        q[P(x, y)] = i + 1;
        q[P(y, x)] = i + 1;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fill(vis, vis + n + 1, 0);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (vis[i] || a[i] == i) continue;

        vector<int> d;
        x = i;
        vis[x] = 1;
        d.push_back(x);
        for (int j = 2; a[x] != i; j++) {
            x = a[x];
            vis[x] = j;
            d.push_back(x);
        }

        int w = d.size();
        vector<int> tp;
        for (auto e:d) {
            sort(g[e].begin(), g[e].end(), [&](int a, int b) {
                int da = vis[a] - vis[e];
                int db = vis[b] - vis[e];
                if (da < 0) da += w;
                if (db < 0) db += w;
                return da < db;
            });

            x = 0;
            for (auto v:g[e]) {
                y = q[P(e, v)];
                if (x) {
                    gd[x].push_back(y);
                    du[y]++;
                } else tp.push_back(y);
                x = y;
            }
        }

        queue<int> tq;
        for (auto e:tp) {
            if (du[e] == 0) {
                tq.push(e);
                du[e] = -1;
            }
        }

        while (!tq.empty()) {
            x = tq.front();
            tq.pop();
            ans.push_back(x);
            for (auto v:gd[x]) {
                if (--du[v] == 0) tq.push(v);
            }
        }
    }

    for (auto e:ans) cout << e << " ";
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
    //cin >> pT;
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}