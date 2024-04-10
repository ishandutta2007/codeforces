#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int a[1000010];
vector <int> b;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, d; scanf("%d%d", &n, &d);
		int lim = gcd(d, n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		for (int r = 0; r < lim; r++) {
			b.clear(), b.push_back(a[r]); int cnt = a[r];
			for (int i = (r + d) % n; i != r; i = (i + d) % n) {
				b.push_back(a[i]), cnt += a[i];
			}
			if (cnt == b.size()) {
				printf("-1\n");
				goto END;
			}
			for (int beg = 0; beg < b.size(); beg++) {
				if (b[beg] == 0) {
					for (int i = beg; i < beg + b.size(); i++) {
						if (!b[i % b.size()]) continue;
						int j = i; while (j < beg + b.size() && b[j % b.size()]) j++;
						ans = max(ans, j - i), i = j - 1;
					}
					break;
				}
			}
		}
		printf("%d\n", ans);
		END:;
	}
	return 0;
}