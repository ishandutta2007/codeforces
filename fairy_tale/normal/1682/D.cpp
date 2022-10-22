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

int prev(int x, int n) {
    if (--x < 0) x += n;
    return x;
}

int nxt(int x, int n) {
    if (++x == n) x = 0;
    return x;
}

void solve()
{
    int n;
    string s;
    vector<int> d;
    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') d.push_back(i);
    }

    if (d.size() == 0 || (d.size() % 2)) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    int m = d.size();
    d.push_back(d[0]);

    vector<vector<int> >g;
    for (int i = 0; i < m; i += 2) {
        int u = d[i], v = d[i + 1];
        int r = d[i + 2];
        vector<int> f;

        int x = u;
        while (x != v) {
            f.push_back(x);
            x = nxt(x, n);
        }

        x = prev(r, n);
        while (x != v) {
            f.push_back(x);
            x = prev(x, n);
        }
        f.push_back(v);
        g.push_back(f);
    }

    m = g.size();
    int p = g[0][0];
    for (int i = m - 1; i > 0; i--) {
        cout << p + 1 << " " << g[i][0] + 1 << endl;
        p = g[i][0];
        int mm = g[i].size();
        for (int j = 1; j < mm; j++) cout << g[i][j - 1] + 1 << " " << g[i][j] + 1 << endl;
    }

    m = g[0].size();
    for (int i = 1; i < m; i++) {
        cout << p + 1 << " " << g[0][i] + 1 << endl;
        p = g[0][i];
    }
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