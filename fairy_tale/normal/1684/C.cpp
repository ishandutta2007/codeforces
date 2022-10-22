#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
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

vector<int> f[maxn], g;
void solve()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) f[i].resize(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> f[i][j];
    }

    P ans = P(-1, -1);
    for (int i = 0; i < n; i++) {
        g = f[i];
        sort(g.begin(), g.end());
        vector<int> d;
        for (int j = 0; j < m; j++) {
            if (g[j] != f[i][j]) d.push_back(j);
        }

        if (d.size() > 2) {
            cout << -1 << endl;
            return;
        }

        if (d.size() > 0) {
            ans = P(d[0], d[1]);
        }
    }

    if (ans.fi != -1) {
        for (int i = 0; i < n; i++) swap(f[i][ans.fi], f[i][ans.se]);
        for (int i = 0; i < n; i++) {
            g = f[i];
            sort(g.begin(), g.end());
            for (int j = 0; j < m; j++) {
                if (g[j] != f[i][j]) {
                    cout << -1 << endl;
                    return;
                }
            }

        }
    }

    if (ans.fi == -1) cout << "1 1" << endl;
    else cout << ans.fi + 1 << " " << ans.se + 1 << endl;
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