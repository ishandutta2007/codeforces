#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9 + 1;
int a[20], b[100010];
int n;
pair < int, int > pr[100010];
int rmax[100010];
int main() {
	for (int i = 0; i < 6; i++) scanf("%d", a + i);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", b + i);
	int ans = inf;
	for (int i = 0; i < 6; i++) {
		int base = b[0] - a[i];
		for (int j = 0; j < n; j++) {
			int l = inf, r = inf;
			for (int k = 0; k < 6; k++) {
				int now = b[j] - a[k];
				if (now <= base) l = min(l, base - now);
				if (now >= base) r = min(r, now - base);
			}
			pr[j] = make_pair(l, r);
		}
		sort(pr, pr + n);
		for (int j = n - 1; j >= 0; j--) rmax[j] = max(rmax[j + 1], pr[j].second);
		for (int j = -1; j < n; j++) {
			if (rmax[j + 1] == inf) continue;
			if (j != -1 && pr[j].first == inf) continue;
			ans = min(ans, rmax[j + 1] + (j == -1 ? 0 : pr[j].first));
		}
	}
	printf("%d\n", ans);
}