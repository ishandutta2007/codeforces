#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int MAXN = 100005;
int p[MAXN], lft[MAXN], rgt[MAXN], n;
 
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", p + i);
	lft[1] = rgt[n] = 1;
	int mx = 1;
	for (int i = 2; i <= n; i++) {
		lft[i] = p[i] > p[i - 1] ? lft[i - 1] + 1 : 1;
		mx = max(mx, lft[i]);
	}
	for (int i = n - 1; i > 0; i--) {
		rgt[i] = p[i] > p[i + 1] ? rgt[i + 1] + 1 : 1;
		mx = max(mx, rgt[i]);
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
		c += lft[i] == mx || rgt[i] == mx;
	if (c > 1) return puts("0"), 0;
	int ans = 0;
	for (int i = 2; i < n; i++) {
		if (p[i] > p[i - 1] && p[i] > p[i + 1]) {
			int m = max(lft[i], rgt[i]);
			if ((m & 1) && m == mx && lft[i] == rgt[i]) ++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}