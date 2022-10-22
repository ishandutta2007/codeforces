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
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);

    int idx = -1;
    LL s = 0;
    while (idx + 1 < n && s + a[idx + 1] <= x) {
        idx++;
        s += a[idx];
    }

    LL ans = 0, pre = 0, now;
    while (idx >= 0) {
        now = (x - s) / (idx + 1) + 1;
        ans += (now - pre) * (idx + 1);
        s -= a[idx];
        idx--;
        pre = now;
    }

    cout << ans << endl;
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