#include <bits/stdc++.h>

using namespace std;

int t, n, c, a[1000000], sum[1000001];
bool v[1000001];

bool work() {
	for (int i = 1; i <= c; ++i) v[i] = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		v[a[i]] = 1;
	}
	for (int i = 1; i <= c; ++i) sum[i] = sum[i - 1] + v[i];
	sort(a, a + n);
	n = unique(a, a + n) - a;
	for (int i = 1; i <= c; ++i)
		if (!v[i])
			for (int j = 0; j < n && (long long)a[j] * i <= c; ++j)
				if (sum[min(c, a[j] * (i + 1) - 1)] - sum[a[j] * i - 1])
					return 0;
	return 1;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &c);
		puts(work() ? "Yes" : "No");
	}
	return 0;
}