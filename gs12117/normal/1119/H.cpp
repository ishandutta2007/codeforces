#include<cstdio>
const int mod = 998244353;
int n, m;
int s[100100][3];
int p[3];
int r[1 << 17];
int c[3][1 << 17];
long long int pow(int x, int y) {
	if (y == 0)return 1;
	long long int r = pow(x, y / 2);
	r *= r;
	r %= mod;
	if (y % 2 == 1) {
		r *= x;
		r %= mod;
	}
	return r;
}
void conv(int s, int d) {
	if (d == 0)return;
	int hd = 1 << (d - 1);
	for (int i = 0; i < hd; i++) {
		int p = (r[s + i] + r[s + i + hd]) % mod;
		r[s + i + hd] = (mod + r[s + i] - r[s + i + hd]) % mod;
		r[s + i] = p;
	}
	conv(s, d - 1);
	conv(s + hd, d - 1);
}
int main() {
	scanf("%d%d", &n, &m);
	scanf("%d%d%d", &p[0], &p[1], &p[2]);
	int sans = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &s[i][0], &s[i][1], &s[i][2]);
		sans ^= s[i][0];
		s[i][1] ^= s[i][0];
		s[i][2] ^= s[i][0];
	}
	for (int i = 0; i < (1 << m); i++) {
		r[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		r[s[i][1]]++;
	}
	conv(0, m);
	for (int i = 0; i < (1 << m); i++) {
		c[0][i] = r[i];
		r[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		r[s[i][2]]++;
	}
	conv(0, m);
	for (int i = 0; i < (1 << m); i++) {
		c[1][i] = r[i];
		r[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		r[s[i][1] ^ s[i][2]]++;
	}
	conv(0, m);
	for (int i = 0; i < (1 << m); i++) {
		c[2][i] = r[i];
		r[i] = 0;
	}
	for (int i = 0; i < (1 << m); i++) {
		int pa = (c[0][i] + n) % mod / 2;
		int pb = (c[1][i] + n) % mod / 2;
		int pc = (c[2][i] + n) % mod / 2;
		int pd = (pa + pb + pc - n) / 2;
		pa -= pd;
		pb -= pd;
		pc -= pd;
		long long int muls = 1;
		muls *= pow(p[0] + p[1] - p[2], pa);
		muls %= mod;
		muls *= pow(p[0] - p[1] + p[2], pb);
		muls %= mod;
		muls *= pow(p[0] - p[1] - p[2], pc);
		muls %= mod;
		muls *= pow((p[0] + p[1]) % mod + p[2], pd);
		muls %= mod;
		if (muls < 0)muls += mod;
		r[i] = muls;
	}
	conv(0, m);
	long long int mans = pow(1 << m, mod - 2);
	for (int i = 0; i < (1 << m); i++) {
		r[i] = r[i] * mans%mod;
	}
	for (int i = 0; i < (1 << m); i++) {
		printf("%d ", r[sans^i]);
	}
	return 0;
}