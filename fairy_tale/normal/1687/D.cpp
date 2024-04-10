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

const int maxn = 2e6 + 5;
const int mod = 998244353;

int l[maxn], r[maxn], a[maxn];
void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        l[a[i]] = a[i];
        r[a[i]] = a[i];
    }

    for (int i = a[1] + 1; i <= a[n]; i++) {
        if (!l[i]) l[i] = l[i - 1];
    }
    for (int i = a[n] - 1; i >= a[1]; i--) {
        if (!r[i]) r[i] = r[i + 1];
    }

    LL dl, dr;
    for (LL i = 1; true; i++) {
        if (a[1] > i * (i + 1)) continue;
        dr = i * (i + 1) - a[1];
        dl = max(0LL, i * i - a[1]);

        for (LL j = 0; true; j++) {
            LL ed = (i + j) * (i + j + 1);
            LL tmp = ed - dl;

            if (tmp >= a[n]) break;
            dr = min(dr, ed - l[tmp]);
            dl = max(dl, (i + j + 1) * (i + j + 1) - r[tmp + 1]);
        }

        if (dl <= dr) {
            cout << dl << endl;
            return;
        }
    }
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