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

const int maxn = 1e5 + 5;
const int mod = 998244353;

bool merge(vector<int> &a, vector<int> &b) {
    vector<int> d(205, -1);
    int n = a.size(), m = b.size();
    for (int i = 0; i < n; i++) d[a[i]] = i;
    for (int i = 0; i < m; i++) {
        int x = b[i];
        if (d[x - 1] >= 0 || d[x + 1] >= 0) {
            vector<int> u(n + m);
            if (d[x - 1] >= 0) x = d[x - 1];
            else x = d[x + 1];
            for (int j = 0; j <= x; j++) u[j] = a[j];
            for (int j = 0; j < m; j++) u[j + x + 1] = b[(j + i + 1) % m];
            for (int j = x + 1, r = m + x + 1; j < n; j++, r++) u[r] = a[j];
            a = u;

            return true;
        }
    }
    return false;
}

int p[maxn], vis[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<vector<int> >f;
    fill(vis, vis + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        vector<int> d;
        int x = i;
        vis[x] = i;
        d.push_back(x);
        while (p[x] != i) {
            x = p[x];
            d.push_back(x);
            vis[x] = i;
        }
        reverse(d.begin(), d.end());
        f.push_back(d);
    }

    int m = f.size();
    fill(vis, vis + m, 0);
    int t = 1;
    while (t < m) {
        for (int i = 1; i < m; i++) {
            if (vis[i]) continue;
            if (merge(f[0], f[i])) {
                vis[i] = 1;
                t++;
            }
        }
    }

    for (auto e:f[0]) cout << e << " ";
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
    while (pT--)
    {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}