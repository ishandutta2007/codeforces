#include <bits/stdc++.h>

using namespace std;

int t, n, a[1000][5], s[4];
bool ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < 5; ++j)
				scanf("%d", &a[i][j]);
		ans = 0;
		for (int i = 0; i < 5; ++i)
			for (int j = i + 1; j < 5; ++j) {
				memset(s, 0, sizeof(s));
				for (int k = 0; k < n; ++k) ++s[a[k][i] + a[k][j] * 2];
				if (s[0] == 0 && s[1] <= n / 2 && s[2] <= n / 2) {
					ans = 1;
					break;
				}
			}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}