#include <bits/stdc++.h>
using namespace std;

vector <int> lef, rig;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		lef.clear(), rig.clear();
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if (x > 0) lef.push_back(x);
			else rig.push_back(-x);
		}
		sort(lef.begin(), lef.end()), sort(rig.begin(), rig.end());
		long long ans = 0; int maxj = 0;
		int cur = lef.size();
		while (cur > 0) maxj = max(maxj, lef[cur - 1]), ans += lef[cur - 1], cur -= k;
		cur = rig.size();
		while (cur > 0) maxj = max(maxj, rig[cur - 1]), ans += rig[cur - 1], cur -= k;
		printf("%lld\n", ans * 2 - maxj);
	}
	return 0;
}