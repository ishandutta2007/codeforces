#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn = 1000010;
int n, m, a[maxn], b[maxn];
ll K, cnt[maxn], pos[maxn];

int main() {
	scanf("%d %d %lld", &n, &m, &K);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		assert(a[i] <= 1000000);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &b[i]);
		assert(b[i] <= 1000000);
	}
	if (n > m) {
		swap(n, m), swap(a, b);
	}
	memset(pos, -1, sizeof(pos));
	for (int i = 0; i < m; i++) {
		pos[b[i]] = i;
	}
	for (int i = 0; i < n; i++) if (~pos[a[i]]) {
		cnt[(pos[a[i]] - i + m) % m]++;
	}
	auto calc = [&](ll x) {
		ll ans = 0;
		for (ll i = 0; i < x / n; i++) {
			ans += n - cnt[i * n % m];
		}
		for (ll i = x / n * n; i < x; i++) {
			if (a[i % n] ^ b[i % m]) ans++;
		}
		return ans;
	};
	ll cyc = 1LL * n * m, num = calc(cyc);
	ll l = 0, r = 2e18, ans = -1;
	while (l <= r) {
		ll mid = (l + r) >> 1;
		ll v = mid / cyc * num + calc(mid % cyc);
		v >= K ? r = (ans = mid) - 1 : l = mid + 1;
	}
	assert(~ans), printf("%lld\n", ans);
	return 0;
}