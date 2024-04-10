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

set<P> q1, q2;

int a[maxn], b[maxn];

void init()
{

}


LL calc(int d, int c)
{
    if (c < 0) return 1LL * d * d;
    if (c > d) return 1LL * mod * mod;

    c++;
    int d1 = d / c;
    int d2 = d1 + 1;
    int m2 = d % c;
    int m1 = c - m2;

    return 1LL * d1 * d1 * m1 + 1LL * d2 * d2 * m2;
}

P check(int n, LL dis)
{
    LL s = 0, m = 0;
    for (int i = 1; i <= n; i++) {
        int d = a[i] - a[i - 1];
        int l = 0, r = d - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            //cout << l << " --- " << r << " " << mid << " :" << calc(d, mid) <<" " << calc(d, mid + 1) << endl;
            if (calc(d, mid) - calc(d, mid + 1) > dis) l = mid + 1;
            else r = mid;
        }

        //cout << dis << " " << l << " " << calc(d, l) << endl;
        m += l;
        s += calc(d, l);
    }

    //cout << dis << " " << s << " ?? " << m << endl;
    return P(s, m);
}

void solve()
{
    int n;
    LL m;
    P ret;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cin >> m;

    LL l = 1, r = m;
    while (l < r) {
        LL mid = (l + r) >> 1;
        ret = check(n, mid);
        if (ret.fi < m) l = mid + 1;
        else r = mid;
    }

    ret = check(n, l);
    cout << ret.se + (ret.fi - m + l - 1) / l << endl;
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