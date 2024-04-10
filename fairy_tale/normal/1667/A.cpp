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
const int maxn = 1e5 + 5;

int a[maxn];

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    LL ans = 1e18;
    for (int i = 0; i < n; i++) {
        LL w = 0, x = 0, k;
        for (int j = i - 1; j >= 0; j--) {
            k = x / a[j] + 1;
            w += k;
            x = k * a[j];
        }

        x = 0;
        for (int j = i + 1; j < n; j++) {
            k = x / a[j] + 1;
            w += k;
            x = k * a[j];
        }

        ans = min(ans, w);
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
    //cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}