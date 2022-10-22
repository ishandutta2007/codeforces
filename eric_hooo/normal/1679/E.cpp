#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

long long power(long long a, int b) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % mod;
		a = a * a % mod, b >>= 1;
	}
	return ans;
}

int n;
char s[1010];
int f[20][1 << 17];
int pw[20][1010];
int ipw[20][1010];
int cnt[1 << 17];

bool Calc(int &mask, int &free, char x, char y) {
	if (x == y) {
		free += x == '?';
	} else {
		if (x != '?' && y != '?') return 0;
		if (x != '?') mask |= 1 << x - 'a';
		if (y != '?') mask |= 1 << y - 'a';
		free++;
	}
	return 1;
}

void Append(int mask, int free) {
	for (int t = 0; t <= 17; t++) {
		ADD(f[t][mask], ipw[t][free]);
	}
}

int main() {
	cnt[0] = 0; for (int i = 1; i < (1 << 17); i++) cnt[i] = cnt[i >> 1] + (i & 1);
	for (int j = 0; j <= 17; j++) {
		int invj = power(j, mod - 2);
		pw[j][0] = 1; for (int i = 1; i <= 1005; i++) pw[j][i] = 1ll * pw[j][i - 1] * j % mod;
		ipw[j][0] = 1; for (int i = 1; i <= 1005; i++) ipw[j][i] = 1ll * ipw[j][i - 1] * invj % mod;
	}
	scanf("%d", &n);
	scanf("%s", s);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		tot += s[i] == '?';
	}
	{ // odd
		for (int i = 0; i < n; i++) {
			int mask = 0, free = 0;
			for (int j = 0; ; j++) {
				if (i - j < 0 || i + j >= n) break;
				if (!Calc(mask, free, s[i - j], s[i + j])) break;
				if (j == 0 && s[i] == '?') free--;
				// cerr << "                                  rng:" << i - j << " " << i + j << endl;
				Append(mask, free);
			}
		}
	}
	{ // even
		for (int i = 0; i + 1 < n; i++) {
			int mask = 0, free = 0;
			for (int j = 0; ; j++) {
				if (i - j < 0 || i + j + 1 >= n) break;
				if (!Calc(mask, free, s[i - j], s[i + j + 1])) break;
				// cerr << "                                  rng:" << i - j << " " << i + j + 1 << endl;
				Append(mask, free);
			}
		}
	}
	for (int t = 0; t <= 17; t++) {
		for (int i = 0; i < 17; i++) {
			for (int mask = 0; mask < (1 << 17); mask++) {
				if (mask >> i & 1) ADD(f[t][mask], f[t][mask ^ 1 << i]);
			}
		}
	}
	int q; scanf("%d", &q);
	while (q--) {
		static char buf[30]; scanf("%s", buf);
		int len = strlen(buf);
		int mask = 0;
		for (int i = 0; i < len; i++) {
			mask |= 1 << buf[i] - 'a';
		}
		printf("%lld\n", 1ll * f[cnt[mask]][mask] * pw[cnt[mask]][tot] % mod);
	}
	return 0;
}