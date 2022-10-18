#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
const int mod = 998244353;
using ll = long long;
int n,a[maxn],b[maxn],f[maxn],cnt[maxn],fac[maxn],ifac[maxn];
int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }
int binom(int n,int m) { return (ll) fac[n] * ifac[m] % mod * ifac[n - m] % mod; }
int ibinom(int n,int m) { return (ll) ifac[n] * fac[m] % mod * fac[n - m] % mod; }

void solve() {
	int ans = 0, sum = 0;
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) {
		a[i] = b[i] = f[i] = cnt[i] = 0;
	}
	fac[0] = ifac[0] = ifac[1] = 1;
	for (int i = 1; i <= n; ++ i) fac[i] = (ll) fac[i - 1] * i % mod;
	for (int i = 1; i <= n; ++ i) ifac[i] = inv(fac[i]);
	int g = 0;
	for (int i = 1; i <= n; ++ i) {
		int x;
		scanf("%d",&x);
		a[x] ++;
	} for (int i = 1; i <= n; ++ i) g = std::__gcd(a[i],g);
	std::vector<int>vc;
	for (int i = 1; i <= n; ++ i) if (a[i]) vc.push_back(a[i]);
	if (g == n) { puts("1"); return ; }
	for (int i = 1; i <= n; ++ i) {
		if (g % i != 0) continue;
		int sum = 0, prod = 1;
		for (int x:vc) {
			sum += x / i;
			prod = (ll) prod * binom(sum,x / i) % mod;
		//	printf("binom(%d %d) = %d\n",sum,b[j],binom(sum,b[j]));
		} cnt[i] = prod;
		f[i] = prod;
	//	printf("cnt[%d] = %d\n",i,cnt[i]);
		for (int x:vc) {
			if (x / i <= 1) continue;
			int way = (ll) prod * ibinom(sum,x / i) % mod * binom(sum - 2,x / i - 2) % mod;
		//	printf("f -= %d\n",way);
			f[i] = (f[i] - way + mod) % mod;
		} //printf("f[%d] = %d\n",i,f[i]);
		f[i] = (ll) f[i] * n % mod;
	}
	for (int d = 1; d <= n; ++ d) {
		int cycle = std::__gcd(d,n);
		int group = n / cycle;
		if (g % group != 0) continue;
	//	printf("+= %d\n",group);
		ans = (ans + f[group]) % mod;
		sum = (sum + cnt[group]) % mod;
	}// printf("%d %d\n",ans,sum);
	ans = (ll) ans * inv(sum) % mod;
	printf("%d\n",ans);
	return ;
}

int main() {
	int t;scanf("%d",&t);while (t--)solve();
	return 0;
}