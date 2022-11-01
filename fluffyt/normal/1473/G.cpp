#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

namespace NTT {
	const int BIT = 16, MAXN = 1 << BIT;
    const int MOD = 998244353, G = 3;
    int w[2][MAXN], inv[MAXN], hasinit;//power table
    int modpow(int a, int b) {
        int res = 1;
        for (; b; b >>= 1) {
            if (b & 1) res = (LL)res * a % MOD;
            a = (LL)a * a % MOD;
        }
        return res;
    }
    void init() {
        hasinit = 1;
        int mul = modpow(G, (MOD - 1) >> BIT);
        for (int i = w[0][0] = 1; i < MAXN; i++) w[0][i] = (LL)w[0][i - 1] * mul % MOD;
        mul = modpow(G, MOD - 1 - ((MOD - 1) >> BIT));
        for (int i = w[1][0] = 1; i < MAXN; i++) w[1][i] = (LL)w[1][i - 1] * mul % MOD;
        inv[1] = 1;
        for (int i = 2; i < MAXN; i++) inv[i] = MOD - (LL)MOD / i * inv[MOD % i] % MOD;
    }
    int get_tpow(int n) {//return min{2^k|2^k>=n}
        int k = 1;
        while (k < n) k <<= 1;
        return k;
    }
    void ntt(int *b, int n, int rev) {
        if (!hasinit) init();
        typedef unsigned long long ull;
        static ull a[MAXN]; static int ww[MAXN];
        const ull mmod = (ull)MOD * MOD; const int *W = w[rev];
        for (int i = 0, j = 0; i < n; i++) {
            a[i] = b[j];
            for (int k = n >> 1; (j ^= k) < k; k >>= 1);
        }
        int n0 = __builtin_ctz(n);
        if (n0 & 1) {
            for (int i = 0; i < n; i += 2) {
                const ull x = a[i], y = a[i + 1];
                a[i] = x + y, a[i + 1] = x + MOD - y;
            }
        }
        for (int h = n0 & 1 ? 4 : 2; h <= n; h <<= 2) {
            int hh = h >> 1, t = (1 << BIT) / h >> 1;
            for (int i = 0; i < h; i++) ww[i] = W[i * t];
            for (int i = 0; i < n; i += h << 1) {
                ull *ax = a + i, *ay = a + i + hh, *au = a + i + h, *av = a + i + h + hh;
                register int *aw = ww, *bw = ww, *cw = ww + hh;
                for (register int j = i; j < i + hh; ++j, ++ax, ++ay, ++au, ++av, aw += 2, ++bw, ++cw) {
                    const ull x = *ax, y = *ay % MOD * *aw, u = *au, v = *av % MOD * *aw;
                    const ull p = x + y, q = x + mmod - y, o = (u + v) % MOD * *bw, r = (u + mmod - v) % MOD * *cw;
                    *ax = p + o, *ay = q + r, *au = p + mmod - o, *av = q + mmod - r;
                }
            }
            if (h == 65536 || h == 32768) for (int j = 0; j < n; j++) a[j] %= MOD;
        }
        for (int i = 0; i < n; i++) b[i] = a[i] % MOD;
        if (rev) {
            int inv = modpow(n, MOD - 2);
            for (int i = 0; i < n; i++) b[i] = (LL)b[i] * inv % MOD;
        }
    }
    //reset a polynomial to zero
    void reset(int *a, int n) { memset(a, 0, sizeof(int) * n); }
    //copy polynomial a to b
    void copy(int *a, int *b, int n) { memcpy(b, a, sizeof(int) * n); }
    //get multiplication of two polynomial in O(nlogn)
    void get_mul(int *a, int *b, int *c, int n, int m, int p) {
        if ((LL)n * m <= 4096) {
            typedef unsigned long long ull;
            static ull res[MAXN];
            for (int i = 0; i < p; i++) res[i] = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m && i + j < p; j++) res[i + j] += (ull)a[i] * b[j];
                if (!(i & 15)) for (int j = 0; j < p; j++) res[j] %= MOD;
            }
            for (int i = 0; i < p; i++) c[i] = res[i] % MOD;
        } else {
            static int A[MAXN], B[MAXN];
            int len = get_tpow(n + m - 1);
            reset(A, len), reset(B, len);
            copy(a, A, n), copy(b, B, m);
            ntt(A, len, 0), ntt(B, len, 0);
            for (int i = 0; i < len; i++) A[i] = (LL)A[i] * B[i] % MOD;
            ntt(A, len, 1);
            copy(A, c, p);
        }
    }
}

const int MAXN = 5005, MAXM = 200005, MOD = 998244353;
LL fac[MAXM], inv[MAXM], f[MAXN], g[MAXN];
int n, a[MAXN], b[MAXN], A[MAXN << 1], B[MAXN << 1];
LL modpow(LL a, int b) {
	LL res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}

void init() {
	int n = 2e5;
	for (int i = fac[0] = 1; i <= n; i++) fac[i] = fac[i - 1] * i % MOD;
	inv[n] = modpow(fac[n], MOD - 2);
	for (int i = n; i > 0; i--) inv[i - 1] = inv[i] * i % MOD;
}

LL C(int a, int b) {
	return a < b ? 0 : fac[a] * inv[b] % MOD * inv[a - b] % MOD;
}

int main() {
	init();
	scanf("%d", &n);
	int m = 1;
	f[1] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", a + i, b + i);
		if (a[i] >= b[i]) {
			for (int j = b[i] + 1; j <= a[i]; j++) {
				memset(g, 0, sizeof(g));
				for (int k = 1; k <= m; k++) {
					(g[k] += f[k]) %= MOD;
					(g[k + 1] += f[k]) %= MOD;
				}
				memcpy(f, g, sizeof(g));
				++m;
			}
			a[i] = b[i];
		}
		memset(g, 0, sizeof(g));
		memset(A, 0, sizeof(A));
		memset(B, 0, sizeof(B));
		for (int j = 1; j <= m; j++) A[j] = f[j];
		for (int j = 0; j <= m; j++) B[j] = C(2 * a[i], a[i] + j);
		NTT::get_mul(A, B, A, m + 1, m + 1, m + 1);
		for (int j = 1; j <= m; j++) g[j] = A[j];
		memset(A, 0, sizeof(A));
		for (int j = 1; j <= m; j++) A[j] = f[j];
		reverse(A, A + m + 1);
		NTT::get_mul(A, B, A, m + 1, m + 1, m * 2 + 1);
		for (int j = 1; j <= m; j++) g[j] = (g[j] + A[m - j]) % MOD;
		for (int j = 1; j <= m; j++)
			g[j] = (g[j] + C(2 * a[i], a[i]) * (MOD - f[j])) % MOD;
		memcpy(f, g, sizeof(g));
		for (int j = a[i] + 1; j <= b[i]; j++) {
			memset(g, 0, sizeof(g));
			for (int k = 1; k < m; k++)
				g[k] = (f[k] + f[k + 1]) % MOD;
			memcpy(f, g, sizeof(g));
			--m;
		}
	}
	LL ans = 0;
	for (int i = 1; i <= m; i++) ans = (ans + f[i]) % MOD;
	printf("%lld\n", ans);
	return 0;
}