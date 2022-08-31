// gf^2 - f + 1 = 0 \
f = (1 - sqrt(1 - 4g)) / 2g = 2 / (1 + sqrt(1 - 4g))
// f ^ 2 - g \
f = f0 - (f0 ^ 2 - g) / 2f0

#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353, GG = 3, GGinv = (mod + 1) / 3;
int rev[530010], G[530010], Ginv[530010];
inline int power(int a, int b) {
	long long res = a, ans = 1;
	for(; b; b >>= 1, res = res * res % mod) if(b & 1) ans = ans * res % mod;
	return ans;
}
inline void NTT(int *a, int l, int type) {
	for(int i = 0; i < (1 << l); i++) if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int p = 1; p < (1 << l); p <<= 1) {
		int wn = (type == 1 ? G[p] : Ginv[p]);
		for(int s = 0; s < (1 << l); s += p << 1) {
			int w = 1;
			for(int i = 0; i < p; i++) {
				int h1 = a[s + i], h2 = 1ll * a[s + p + i] * w % mod;
				a[s + i] = (h1 + h2) % mod;
				a[s + i + p] = (h1 - h2 + mod) % mod;
				w = 1ll * w * wn % mod;
			}
		}
	}
	if(type == -1) {
		int inv = power(1 << l, mod - 2);
		for(int i = 0; i < (1 << l); i++) a[i] = 1ll * a[i] * inv % mod;
	}
}
inline void get_rev(int l) {
	for(int i = 1; i < (1 << l); i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
}
int tmp1[530010], tmp2[530010], tmp3[530010], tmp4[530010], tmp5[530010];
inline void mult(int *a, int sizea, int *b, int sizeb, int *c) {
	int l = 0;
	for(; (1 << l) < sizea + sizeb - 1; l++);
	get_rev(l);
	for(int i = 0; i < (1 << l); i++) {
		if(i < sizea) tmp1[i] = a[i]; else tmp1[i] = 0;
		if(i < sizeb) tmp2[i] = b[i]; else tmp2[i] = 0;
	}
	NTT(tmp1, l, 1);
	NTT(tmp2, l, 1);
	for(int i = 0; i < (1 << l); i++) tmp1[i] = 1ll * tmp1[i] * tmp2[i] % mod;
	NTT(tmp1, l, -1);
	for(int i = 0; i < sizea + sizeb - 1; i++) c[i] = tmp1[i];
}
inline void inv(int *a, int sizea, int *b, int sizeb) {
	b[0] = power(a[0], mod - 2);
	for(int now = 1; now < sizeb; now <<= 1) {
		mult(b, now, b, now, tmp3);
		mult(tmp3, now + now - 1, a, min(sizea, now << 1), tmp3);
		for(int i = 0; i < now << 1; i++)
			if(i < now) b[i] = (2ll * b[i] + mod - tmp3[i]) % mod;
			else b[i] = (mod - tmp3[i]) % mod;
	}
}
inline void sqrt(int *a, int sizea, int *b, int sizeb) {
	b[0] = 1;
	for(int now = 1; now < sizeb; now <<= 1) {
		mult(b, now, b, now, tmp4);
		tmp4[now + now - 1] = 0;
		for(int i = 0; i < now << 1; i++)
			if(i < sizea) tmp4[i] = (tmp4[i] - a[i] + mod) % mod;
		inv(b, now, tmp5, now << 1);
		int inv2 = (mod + 1) / 2;
		for(int i = 0; i < now << 1; i++) tmp5[i] = 1ll * inv2 * tmp5[i] % mod;
		mult(tmp4, now << 1, tmp5, now << 1, tmp4);
		for(int i = 0; i < now << 1; i++)
			if(i < now) b[i] = (b[i] - tmp4[i] + mod) % mod;
			else b[i] = (mod - tmp4[i]) % mod;
	}
}
int n, m;
int c[530010], sqinv[530010], sq[530010];
int main() {
	for(int i = 1; i < 530010; i <<= 1) G[i] = power(GG, (mod - 1) / 2 / i), Ginv[i] = power(GGinv, (mod - 1) / 2 / i);
	scanf("%d%d", &n, &m);
	m++;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		c[x] = -4;
	}
	c[0] = 1;
	sqrt(c, m, sq, m);
	sq[0]++;
	inv(sq, m, sqinv, m);
	for(int i = 1; i < m; i++) {
		int ans = sqinv[i];
		printf("%d\n", sqinv[i] * 2 % mod);
	}
	return 0;
}