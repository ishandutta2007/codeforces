// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, p[N], p1[N], p0[N], s1[N], s0[N], x[N], y[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		p0[i] = p1[i] = s1[i] = s0[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		if (p[i - 1] > p[i]) p0[i] += p0[i - 1];
		else p1[i] += p1[i - 1];
		x[i] = max(x[i - 1], max(p1[i], p0[i]));
	}
	for (int i = n - 1; i; i--) {
		if (p[i] > p[i + 1]) s0[i] += s0[i + 1];
		else s1[i] += s1[i + 1];
		y[i] = max(y[i + 1], max(s1[i], s0[i]));
	}
	for (int i = 1; i <= n; i++) {
		int A = p1[i], B = s0[i];
		if (A != B) continue;
		if (A % 2 == 0) continue;
		int t = max(x[i - A + 1], y[i + B - 1]);
		if (t >= A) continue;
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}