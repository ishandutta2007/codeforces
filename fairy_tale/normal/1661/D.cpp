#include<bits/stdc++.h>
#define fi first
#define se second
#define lson(x) ((x) << 1)
#define rson(x) ((x) << 1 | 1)
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#endif

using namespace std;
typedef long long LL;
typedef pair<LL, LL> P;

const int maxn = 3e5 + 5;
const int mod = 1e9 + 7;

LL b[maxn];
LL c[maxn];

void init()
{

}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }

    LL ans = 0, pre = 0, m = 0;
    for (int i = n; i > 0; i--) {
        m -= c[i];
        LL t = 0;
        k = min(k, i);
        if (b[i] > pre) t = (b[i] - pre + k - 1) / k;

        if (i > k) c[i - k] = t;
        ans += t;
        m += t;
        pre += t * k;

        pre -= m;
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

    init();

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}