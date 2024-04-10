#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9 + 7;
const int maxn = 5e6 + 7;
int t,l,r,ans;
ll f[maxn];

ll calc(ll x) { return x * (x - 1) / 2; }

int main() {
	scanf("%d%d%d",&t,&l,&r);
	std::memset(f,63,sizeof(f));
	f[1] = 0;
	for (int i = 1; i <= r; ++ i) 
		for (int j = i; j <= r; j += i) f[j] = std::min(f[j],f[i] + calc(j / i) * i );
	int p = 1;
	for (int i = l; i <= r; ++ i) {
		ans = (ans + (ll) p * (f[i] % mod) % mod) % mod;
		p = (ll) p * t % mod;
	}
	printf("%d",ans);
	return 0;
}