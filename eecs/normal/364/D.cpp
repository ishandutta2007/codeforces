#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n, cnt[maxn];
ll ans, a[maxn], num[maxn];
mt19937 rnd(time(0));

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	double st = clock();
	while ((clock() - st) / CLOCKS_PER_SEC < 3) {
		ll x = a[rnd() % n + 1];
		int tot = 0;
		for (ll i = 1; i * i <= x; i++) if (!(x % i)) {
			num[++tot] = i;
		}
		for (ll i = sqrt(x) + 5; i; i--) if (!(x % i)) {
			if (i * i < x) num[++tot] = x / i;
		}
		auto get = [&](ll t) {
			return lower_bound(num + 1, num + tot + 1, t) - num;
		};
		fill(cnt + 1, cnt + tot + 1, 0);
		for (int i = 1; i <= n; i++) {
			cnt[get(__gcd(x, a[i]))]++;
		}
		vector<ll> V;
		for (ll i = 2; i * i <= x; i++) if (!(x % i)) {
			while (!(x % i)) x /= i;
			V.push_back(i);
		}
		if (x > 1) V.push_back(x);
		for (ll p : V) {
			for (int i = tot; i; i--) if (!(num[i] % p)) {
				cnt[get(num[i] / p)] += cnt[i];
			}
		}
		for (int i = 1; i <= tot; i++) {
			if (cnt[i] >= (n + 1) / 2) ans = max(ans, num[i]);
		}
	}
	printf("%lld\n", ans);
	return 0;
}