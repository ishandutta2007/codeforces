#include<bits/stdc++.h>
#define fi first
#define se second
#define LSON t << 1, l, mid
#define RSON t<< 1 | 1, mid + 1, r
#ifdef FEIFEI
#define Debug printf
#else
#define Debug(...)
#define endl '\n'
#endif

using namespace std;
typedef long long LL;
typedef pair<int, int> P;

const int maxn = 2e5 + 5;
const int mod = 998244353;

int add(int x, int y) {
    x += y;
    if(x >= mod) x -= mod;
    return x;
}

int mul(int a, int b) {
    LL r = 1LL * a * b;
    return r - r / mod * mod;
}

int powt(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int a[3005];
LL Lmin[3005], Lmax[3005], Rmin[3005], Rmax[3005];
LL work(int n, LL k)
{
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            Lmin[i] = Lmin[i - 1] - k;
            Lmax[i] = Lmax[i - 1] + k;
        } else {
            Lmin[i] = Lmin[i - 1] + a[i];
            Lmax[i] = Lmax[i - 1] + a[i];
        }
    }

    if (Lmin[n] > 0 || Lmax[n] < 0) return -1;

    for (int i = n; i > 0; i--) {
        if (a[i] == 0) {
            Rmin[i] = Rmin[i + 1] - k;
            Rmax[i] = Rmax[i + 1] + k;
        } else {
            Rmin[i] = Rmin[i + 1] + a[i];
            Rmax[i] = Rmax[i + 1] + a[i];
        }
    }

    LL ans = 1;
    for (int i = 1; i <= n; i++) {
        LL v = max(Lmin[i], -Rmax[i + 1]);

        LL l = v, r = v;
        LL now = v;
        //cout << i << "?? " << v << endl;
        for (int j = i; j > 0; j--) {
            if (a[j] == 0) {
                LL x = min(max(now - Lmax[j - 1], -k), k);
                now -= x;
            } else now -= a[j];
            l = min(l, now);
            r = max(r, now);
            //cout << j << " " << now << endl;
        }

        now = v;
        for (int j = i + 1; j <= n; j++) {
            if (a[j] == 0) {
                LL x = min(max(-Rmin[j + 1] - now, -k), k);
                now += x;
            } else now += a[j];
            l = min(l, now);
            r = max(r, now);
            //cout << j << " " << now << endl;
        }

        ans = max(r - l + 1, ans);
    }
    return ans;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    LL ans = work(n, k);

    for (int i = 1; i <= n; i++) a[i] = -a[i];
    ans = max(ans, work(n, k));

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