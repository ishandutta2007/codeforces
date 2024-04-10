#include <cstdio>
#include <cstring>
const long long MOD = 998244353, MAX_N = 2000;
long long f[2][MAX_N+1][11], g[MAX_N+1] = {1}; int cnt[2];

int dgc(int a) { int c = 0; while (a) a /= 10, ++c; return c; }

void solve() {
	long long ans = cnt[0] = cnt[1] = 0;
	memset(f, 0, sizeof(f));
	f[0][0][0] = f[1][0][0] = 1;
	int n, sum = 0; scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		int a; scanf("%d", &a); 
		(sum += a) %= 11;
		for (int d = dgc(a)&1, j = ++cnt[d]; j > 0; --j)
			for (int k = 0; k < 11; ++k)
				(f[d][j][k] += f[d][j-1][(k+11-a%11)%11]) %= MOD;
	}
	(sum += 11*(sum&1)) >>= 1;
	for (int c, i = 0; i <= cnt[0]; ++i) {
		long long tmp = 0; c = (cnt[1]>>1)+i;
		for (int j = 0; j < 11; ++j)
			(tmp += f[1][cnt[1]>>1][j]*f[0][i][(sum+11-j)%11]%MOD) %= MOD;
		(ans += tmp*(cnt[1]&1?g[c]*g[n-c-1]%MOD*(cnt[1]+1>>1)%MOD:g[c-1]*g[n-c]%MOD*(cnt[1]>>1)%MOD)%MOD) %= MOD;
	}
	printf("%lld\n", cnt[1]?ans:sum?0:g[n]);
}

int main() {
	for (int i = 1; i <= MAX_N; ++i)
		g[i] = g[i-1]*i%MOD;
	int t; scanf("%d", &t);
	while (t--) solve();
}