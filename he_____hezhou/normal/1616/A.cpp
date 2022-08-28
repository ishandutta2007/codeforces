#include <bits/stdc++.h>
using namespace std;
int T, n, cnt[110];
void rmain() {
	scanf("%d", &n);
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		cnt[abs(x)]++;
	}
	int ans = min(1, cnt[0]);
	for (int i = 1; i <= 100; i++) ans += min(2, cnt[i]);
	printf("%d\n", ans);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}