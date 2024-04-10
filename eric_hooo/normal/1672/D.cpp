#include <bits/stdc++.h>
using namespace std;

int a[200010], b[200010];
int ok[200010];
multiset <int> S;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
		}
		for (int i = 1; i <= n; i++) {
			ok[i] = i < n && b[i] == b[i + 1];
		}
		S.clear();
		int p = n, ans = 1;
		for (int i = n; i >= 1; i--) {
			while (p >= 1 && ok[p]) S.insert(b[p]), p--;
			if (p > 0 && a[i] == b[p]) {
				p--;
				continue;
			}
			if (S.find(a[i]) == S.end()) {
				ans = 0;
				goto END;
			}
			S.erase(S.find(a[i]));
		}
		END:;
		printf(ans ? "YES\n" : "NO\n");
	}
	return 0;
}