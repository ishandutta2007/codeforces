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

const int maxn = 1e7 + 5;
const int mod = 998244353;
const int inv2 = (mod + 1) >> 1;

int add(int x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}

int mul(int x, int y) {
    LL z = 1LL * x * y;
    return z - z / mod * mod;
}

int powt(int a, int b) {
    int r = 1;
    while (b) {
        if (b & 1) r = mul(r, a);
        a = mul(a, a);
        b >>= 1;
    }
    return r;
}

int pw[maxn], q[maxn], p[maxn], inv[maxn];
void init() {
    pw[0] = 1;
    for (int i = 1; i < maxn; i++) pw[i] = mul(pw[i - 1], 2);

    p[0] = pw[0];
    for (int i = 1; i < maxn; i++) q[i] = add(q[i - 1], pw[i - 1]);
    for (int i = 1; i < maxn; i++) p[i] = mul(q[i], p[i - 1]);
    inv[maxn - 1] = powt(p[maxn - 1], mod - 2);
    for (int i = maxn - 1; i > 0; i--) inv[i - 1] = mul(inv[i], q[i]);
	for (int i = 1; i < maxn; i++) inv[i] = mul(inv[i], p[i - 1]);
}

void solve()
{
    int n, k, x, ans = 0;
    cin >> n >> k >> x;
    if (x == 0) {
        if (k >= n) {
            ans = 1;
            for (int i = 0; i < n; i++) ans = mul(ans, add(pw[k], mod - pw[i]));
        }
    } else {
		int x = powt(2, n);
        int tmp = mul(x - 1, inv[1]);
        for (int i = 1; i <= min(n, k); i++) {
            tmp = mul(tmp, add(pw[k], mod - pw[i - 1]));
            ans = add(ans, mul(tmp, pw[i] - 1));
			x = mul(x, inv2);
			tmp = mul(tmp, mul(x - 1, inv[i + 1]));
        }
        ans = mul(ans, powt(pw[k] - 1, mod - 2));
		ans = add(powt(pw[k], n), mod - ans);
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

    init();

    int pT = 1;
    cin >> pT;
    while (pT--) {
        solve();
    }

    Debug("Time: %.3lfs\n", (double)clock() / CLOCKS_PER_SEC);
    return 0;
}