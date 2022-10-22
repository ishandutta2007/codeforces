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

const int mod = 998244353;
const int maxn = 2e5 + 5;

int a[maxn], b[maxn];
vector<int> f[maxn];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) f[i].clear();
    for (int i = 1; i <= n; i++) b[i] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[a[i]]++;
        f[b[a[i]]].push_back(i);
    }

    for (int i = 1; i <= n; i++) {
        if (f[i].size() <= 1) break;
        sort(f[i].begin(), f[i].end(), [&](int x, int y) {
                return a[x] < a[y];
            });

        int m = f[i].size(), k = a[f[i][0]];
        for (int j = 1; j < m; j++) a[f[i][j - 1]] = a[f[i][j]];
        a[f[i][m - 1]] = k;

    }

    for (int i = 1; i <= n; i++) cout << a[i] << " ";
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