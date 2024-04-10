#include <bits/stdc++.h>

#define rep(i, x, y) for (int i = (x), _ = (y); i <= _; ++i)
#define down(i, x, y) for (int i = (x), _ = (y); i >= _; --i)
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define bin(x) (1 << (x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

template<typename T> inline void upmax(T &x, T y) { x < y ? x = y : 0; }
template<typename T> inline void upmin(T &x, T y) { x > y ? x = y : 0; }

const int mod = 1000000007;
const int N = 4005;

inline void upd(int &x, int y) { (x += y) >= mod ? x -= mod : 0; }
inline int add(int x, int y) { return x + y >= mod ? x + y - mod : x + y; }
inline int sub(int x, int y) { return x - y < 0 ? x - y + mod : x - y; }
inline ll mul(ll x, ll y) { return x * y % mod; }

inline int qpow(int x, int n) {
    int ans = 1;
    for (; n; n >>= 1, x = mul(x, x)) if (n & 1) ans = mul(ans, x);
    return ans;
}
inline int inver(int x) {
    return qpow(x, mod - 2);
}

int fac[N], inv[N];

inline int nCr(int n, int m) {
    return n < m ? 0 : mul(fac[n], mul(inv[n - m], inv[m]));
}

int a[4005],b[4005],tp,lst=1;
int f[2][4005];

int main() {
    int n = 4000;
    fac[0] = 1;
    rep (i, 1, n) fac[i] = mul(fac[i - 1], i);
    inv[n] = inver(fac[n]);
    down (i, n, 1) inv[i - 1] = mul(inv[i], i);

	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&b[i]);
	
	
	sort(b+1,b+n+1);
	int tmp = 1;
	for (int i=1;i<=n;i++)
		if (b[i] != b[i-1]) lst = 1ll * lst * qpow(tmp, mod-2); else tmp = 1;
	lst = 1LL * lst * qpow(tmp, mod-2);
	
	
	b[0] = -1;
	for (int i=1;i<=n;i++) {
		int tp = b[i];
		for (int j=2;j<=sqrt(tp);j++) {
			while (b[i]%(j*j) == 0) b[i] /= j * j;
		}
	}
	sort(b+1,b+n+1);
	for (int i=1;i<=n;i++) if (b[i] != b[i-1]) a[tp++] = 1; else a[tp-1]++;
	
        int t = 0;
        int tot = 0;
        f[t][0] = 1;
        rep (s, 0, tp-1) {
            int v = a[s];
            if (!v) continue ;
            rep (i, 0, tot) rep (j, 1, v) {
                int tr = mul(nCr(v - 1, v - j), inv[j]);
                upd(f[t ^ 1][i + j], (int) mul(tr, f[t][i]));
            }
            memset(f[t], 0, sizeof(int) * (tot + 1));
            tot += v;
            t ^= 1;
        }
        int ans = 0;
        rep (i, 0, tot) {
            int tr = f[t][i];
            (tot - i) & 1 ? tr = sub(0, tr) : 0;
            upd(ans, (int) mul(fac[i], tr));
        }
        for (int i=0;i<tp;i++) ans = 1ll * ans * fac[ a[i] ] % mod;
        ans = 1ll * ans * lst % mod;
        printf("%d\n", ans);

    return 0;
}