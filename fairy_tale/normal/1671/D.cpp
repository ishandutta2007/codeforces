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

int a[maxn];

void solve()
{
    int n, x;
    LL ans = 0;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++) ans += abs(a[i] - a[i + 1]);

    int d1 = min(a[1] - 1, a[n] - 1);
    for (int i = 1; i < n; i++) {
        d1 = min(d1, (a[i] + a[i + 1] - 2) - abs(a[i] - a[i + 1]));
    }
    int d2 = min(abs(a[1] - x), abs(a[n] - x));
    for (int i = 1; i < n; i++) {
        d2 = min(d2, abs(a[i] - x) + abs(a[i + 1] - x) - abs(a[i] - a[i + 1]));
    }

    int mn = maxn, mx = 0;
    for (int i = 1; i <= n; i++) {
        mn = min(mn ,a[i]);
        mx = max(mx, a[i]);
    }

    if (x <= mn) d2 = 0;
    if (mx <= 1) d1 = 0;

    cout << ans + d1 + d2 << endl;
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