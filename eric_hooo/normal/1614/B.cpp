#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

pii a[200010];
vector <int> coef;
int vis[200010];
int res[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		coef.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i].fi);
			coef.push_back(i + 2 >> 1);
			vis[coef.back()] = 0;
			a[i].se = i;
		}
		sort(a, a + n), reverse(a, a + n);
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			ans += 2ll * a[i].fi * coef[i];
			res[a[i].se] = vis[coef[i]] ? -coef[i] : coef[i];
			vis[coef[i]] = 1;
		}
		printf("%lld\n", ans);
		printf("0 ");
		for (int i = 0; i < n; i++) {
			printf("%d ", res[i]);
		}
		printf("\n");
	}
	return 0;
}