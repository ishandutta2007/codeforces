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
typedef pair<LL, LL> PL;

const int maxn = 2e5 + 5;
const int mod = 1e9 + 7;

int dp0[maxn], dp1[maxn], a[maxn];

void solve()
{
    LL ans = 0;
    int n, lst, u, v, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    lst = n + 1;
    for (int i = n; i > 0; i--) {
        dp0[i] = u = mod;  // i --> inc
        dp1[i] = v = -mod; // i --> dec
        for (int j = i + 1; j <= n; j++) {
            x = -mod, y = mod;
            if (a[j] > a[j - 1]) x = max(x, u);
            if (a[j] > v) x = max(x, a[j - 1]);
            if (a[j] < a[j - 1]) y = min(y, v);
            if (a[j] < u) y = min(y, a[j - 1]);

            u = x, v = y;
            if (dp0[j] == u && dp1[j] == v) break;
            else dp0[j] = u, dp1[j] = v;

            if (u == -mod && v == mod) {
                lst = j;
                break;
            }
        }

        ans += lst - i;
    }
    cout << ans << endl;
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
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}