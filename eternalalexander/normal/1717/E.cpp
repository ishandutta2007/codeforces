#include <bits/stdc++.h>

const int maxn = 1e6 + 222;
const int mod = 1e9 + 7;
using ll = long long;
int inv(int x) { return x == 1 ? 1 : (ll) ( mod - mod / x ) * inv(mod % x) % mod; }
int n,ans = 0;
ll f[maxn];

int main() {
	scanf("%d",&n);
	for (int x = 1; x <= n; ++ x) {
		int d = n / x;
		for (int i = 1; i <= d; ++ i) {
			f[x] = (f[x] + (ll) (d - i) * (n - i * x) % mod) % mod;
			f[x] = (f[x] - ((ll) x * (1 + d - i) * (d - i) / 2) % mod + mod) % mod;
		}
		
	} 
	for (int i = n; i >= 1; i --) {
		for (int j = i + i; j <= n; j += i) f[i] = (f[i] - f[j] + mod) % mod;
	//	printf("%d : %lld\n",i,f[i]);
	}
	for (int i = 1; i <= n; ++ i) {
		int iv = inv(std::__gcd(n,i));
		ans = (ans + (ll) (f[i] % mod) * i % mod * iv % mod) % mod;
	} printf("%d",ans);
	return 0;
}