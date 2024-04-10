#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 7;

int n,c[maxn],cnt[maxn],tl;
ll ans,a[maxn],h[maxn],b[maxn];
std::set<ll>S;

int main() {
	srand(12345);
	auto rng = []() { return rand() * 32768 + rand(); };
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i) scanf("%lld",&a[i]);
	for (int i = 1; i <= 11; ++ i) {
		int x = rng() % n + 1;
		for (int j = 1; j <= n; ++ j) b[j] = h[j] = std::__gcd(a[x],a[j]);
		std::sort(h+1,h+n+1);
		tl = std::unique(h+1,h+n+1) - (h+1);
		for (int j = 1; j <= n; ++ j) c[j] = std::lower_bound(h+1,h+tl+1,b[j]) - (h+1) + 1;
		for (int j = 1; j <= n; ++ j) cnt[c[j]] ++;
		auto test = [](ll x) {
			if (x <= ans) return;
			int cw = 0;
			for (int j = 1; j <= tl; ++ j) if (h[j] % x == 0) cw += cnt[j];
			if (cw * 2 >= n) ans = std::max(ans,x);
		};
		for (ll d = 1; d * d <= a[x]; ++ d) {
			if (a[x] % d) continue;
			test(d); test(a[x]/d);
		}
		std::memset(cnt,0,sizeof(cnt));
	} printf("%lld",ans);
		
	return 0;
}