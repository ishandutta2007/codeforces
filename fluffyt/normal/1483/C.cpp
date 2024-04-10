#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 300005;
int n, m, h[MAXN], b[MAXN], sta[MAXN], l[MAXN];
LL bit[MAXN], f[MAXN];
void upd(int x, LL y) {
	for (; x <= n + 1; x += x & -x) bit[x] = max(bit[x], y);
}

LL ask(int x) {
	LL ans = -1e18;
	for (; x; x -= x & -x) ans = max(ans, bit[x]);
	return ans;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", h + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	int tp = 0;
	for (int i = 1; i <= n; i++) {
		while (tp > 0 && h[sta[tp]] > h[i]) --tp;
		l[i] = sta[tp];
		sta[++tp] = i;
	}
	for (int i = 1; i <= n; i++) bit[i] = -1e18;
	f[0] = -1e18;
	f[1] = b[1];
	upd(n, f[1]);
	for (int i = 2; i <= n; i++) {
		f[i] = ask(n - l[i] + 1) + b[i];
		f[i] = max(f[i], f[l[i]]);
		upd(n - i + 1, f[i]);
	}
	printf("%lld\n", f[n]);
	return 0;
}