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
const int mod = 998244353;

int a[maxn], b[maxn], c[maxn], d[maxn];

void solve()
{
    int n, s, x;
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        c[a[i]] = i;
    }
    fill(d, d + n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        if (b[i] != -1) d[b[i]] = i;
    }

    int ans = 1, num = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (j <= n && j <= i + s) {
            if (b[c[j]] == -1) num++;
            j++;
        }

        if (d[i] == 0) {
            ans = 1LL * ans * num % mod;
            num--;
        } else {
            //cout << i << " == " << i + s << " " << a[b[i]] << endl;
            if (a[d[i]] > i + s) ans = 0;
        }
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
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}