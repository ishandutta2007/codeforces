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
const int maxn = 2e6 + 5;

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

int v[maxn], p[maxn], inv[maxn];
int C(int n, int k)
{
    int w = p[k];
    return mul(w, powt(k + 1, n));
}

void init()
{
    p[0] = 1;
    for (int i = 1; i < maxn; i++) p[i] = mul(i, p[i - 1]);
    inv[maxn - 1] = powt(p[maxn - 1], mod - 2);
    for (int i = maxn - 1; i > 0; i--) inv[i - 1] = mul(inv[i], i);
}

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> v[i];

    int dp = 0, f0 = 1;
    for (int i = 0; i < n - k; i++) {
        if (v[i] == -1) {
            dp = add(mul(dp, i), mul(dp, k + 1));
            if (f0) dp = add(dp, mul(i, C(i, k)));
            //cout << i << " " << mul(i, C(i, k)) << endl;
        } else {
            if (v[i] != 0 && f0) {
                dp = add(dp, C(i, k));
                f0 = 0;
            } else if (v[i] == 0) {
                dp = mul(dp, k + 1);
            }
        }
    }

    if (f0) dp = add(dp, C(n - k, k));
    for (int i = n - k; i < n; i++) {
        if (v[i] > 0) dp = 0;
    }

    cout << dp << endl;
}

int main()
{
#ifdef FEIFEI
    freopen("E:\\code\\input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    init();

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}