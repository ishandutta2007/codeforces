#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T, n, x;
ll a[50010];
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", a + i);
	scanf("%d", &x);
	for (int i = 1; i <= n; i++) a[i] -= x;
	for (int i = 1; i <= n; i++) a[i] += a[i - 1];
	int ans = 0;
	for (int l = 1, r; l <= n; l = r + 2) {
		ll cur = a[l - 1];
		for (r = l; r < n && a[r + 1] >= cur; r++) {
			cur = max(cur, a[r]);
		}
		ans += r - l + 1;
	}
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}