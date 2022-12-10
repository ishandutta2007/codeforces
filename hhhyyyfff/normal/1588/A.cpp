#include <bits/stdc++.h>

using namespace std;

int t, n, a[100], b[100];
bool ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
		for (int i = 0; i < n; ++i) scanf("%d", &b[i]);
		sort(a, a + n);
		sort(b, b + n);
		ans = 1;
		for (int i = 0; i < n; ++i)
			if (b[i] != a[i] && b[i] != a[i] + 1) {
				ans = 0;
				break;
			}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}