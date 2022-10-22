#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[100010], b[100010], f[100010], g[100010];

bool Check(int mid) {
	// 0 L
	f[0] = 1, g[0] = -0x3f3f3f3f;
	for (int i = 1; i < n; i++) {
		f[i] = -0x3f3f3f3f;
		if (b[i] - mid <= f[i - 1]) f[i] = max(f[i - 1], b[i] + 1);
		if (b[i] - mid <= g[i - 1]) f[i] = max(f[i], max(b[i - 1] + mid + 1, b[i] + 1));
		g[i] = f[i - 1] < b[i] ? f[i - 1] : b[i] + mid + 1;
		g[i] = max(g[i], g[i - 1] < b[i] ? g[i - 1] : b[i] + mid + 1);
	}
	if (f[n - 1] + mid >= m) return 1;
	if (g[n - 1] + mid >= m) return 1;
	// 0 R  1 L
	f[1] = max(b[1] + 1, b[0] + mid + 1), g[1] = -0x3f3f3f3f;
	for (int i = 2; i < n; i++) {
		f[i] = -0x3f3f3f3f;
		if (b[i] - mid <= f[i - 1]) f[i] = max(f[i - 1], b[i] + 1);
		if (b[i] - mid <= g[i - 1]) f[i] = max(f[i], max(b[i - 1] + mid + 1, b[i] + 1));
		g[i] = f[i - 1] < b[i] ? f[i - 1] : b[i] + mid + 1;
		g[i] = max(g[i], g[i - 1] < b[i] ? g[i - 1] : b[i] + mid + 1);
	}
	if (f[n - 1] + max(0, mid - a[0]) >= m) return 1;
	if (g[n - 1] + max(0, mid - a[0]) >= m) return 1;
	return 0;
}

int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	if (n == 1) {
		printf("%d\n", m - 1);
		return 0;
	}
	for (int i = 0; i < n; i++) b[i] = (a[(i + 1) % n] - a[i] + m) % m;
	for (int i = 0; i < n; i++) a[i] = b[i];
	int p = 0; for (int i = 0; i < n; i++) if (a[i] > a[p]) p = i;
	for (int i = 0; i < n; i++) b[i] = a[(p + i + 1) % n];
	for (int i = 0; i < n; i++) a[i] = b[i];
	b[0] = 0; for (int i = 0; i < n; i++) b[i + 1] = b[i] + a[i];
	int l = 0, r = a[n - 1];
	while (l < r) {
		int mid = l + r >> 1;
		if (Check(mid)) r = mid;
		else l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}