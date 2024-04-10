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

int a[maxn], b[maxn], c[maxn];

void solve()
{
    auto query = [](int x) {
        cout << "? " << x << endl;
        cout.flush();

        int h;
        cin >> h;
        return h;
    };

    int n;
    cin >> n;
    int l = n + n - 1, r = 2000 * n + n - 1;
    while (l < r) {
        int mid = (l + r) >> 1;
        int h = query(mid);
        if (h != 1) l = mid + 1;
        else r = mid;
    }

    int ans = l;
    for (int i = 2; i <= n; i++) {
        int h = query(l / i);
        if (h) ans = min(ans, l / i * h);
    }
    cout << "! " << ans << endl;
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