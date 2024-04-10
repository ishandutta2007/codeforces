#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n;
ll a[200010], s[200010];
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + a[i];
	}
	if (a[1] * (n - 2) + s[n] > 0) return puts("INF"), void();
	if (a[n] * (n - 2) + s[n] < 0) return puts("INF"), void();
	ll ans = -0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		ll cur = 0;
		cur += s[i] * a[n];
		cur += (s[n] - s[i]) * a[1];
		cur -= a[1] * a[n];
		cur -= (s[i] + i * a[n]) * a[i];
		cur -= (s[n] - s[i] + (n - i) * a[1]) * a[i];
		cur += (a[1] + a[n]) * a[i];
		ans = max(ans, cur);
	}
	printf("%lld\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}