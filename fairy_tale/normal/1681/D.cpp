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

LL limit;
int ans;

void dfs(LL x, int t) {
    if (t >= ans) return;
    if (x >= limit) {
        ans = min(ans, t);
        return;
    }

    int minT = t;
    for (LL v = x; v < limit; v *= 9) minT++;
    if (minT >= ans) return;

    int mask = 0;
    for (LL v = x; v > 0; v /= 10) mask |= 1 << (v % 10);
    for (int i = 2; i < 10; i++) {
        if ((mask >> i) & 1) dfs(x * i, t + 1);
    }
}

void solve()
{
    LL n, x;
    cin >> n >> x;

    limit = 1;
    ans = mod;
    for (int i = 1; i < n; i++) limit *= 10;
    dfs(x, 0);
    cout << (ans < 200 ? ans : -1) << endl;
}


int main()
{
#ifdef FEIFEI
    //freopen("E:\\code\\input.txt", "r", stdin);
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