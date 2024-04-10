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

string f[1 << 18];

int dfs(string &s, int t, int n)
{
    if (t * 2 > n) { // leaf
        f[t] = s.substr(t - 1, 1);
        return 1;
    }

    int l = dfs(s, t << 1, n);
    int r = dfs(s, t << 1 | 1, n);
    int ret;
    if (f[t << 1] == f[t << 1 | 1]) ret = 1LL * l * r % mod;
    else ret = 2LL * l * r % mod;

    if (f[t << 1] < f[t << 1 | 1]) f[t] = s.substr(t - 1, 1) + f[t << 1] + f[t << 1 | 1];
    else f[t] = s.substr(t - 1, 1) + f[t << 1| 1] + f[t << 1];
    return ret;
}

void solve()
{
    int n;
    string s;
    cin >> n >> s;
    cout << dfs(s, 1, s.size()) << endl;
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
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}