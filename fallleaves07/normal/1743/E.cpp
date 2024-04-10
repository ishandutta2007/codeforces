#include<bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	const LL lnf = 1e18;
	LL p1, t1, p2, t2, h, s, ans = lnf;
	cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
	vector<LL> cost(h, lnf), res(h, lnf);
	for (int i = 0; i <= h; i++) {
		for (int j = 0; j <= h; j++) {
			LL damage = 1ll * i * (p1 - s) + 1ll * j * (p2 - s);
			LL t = max(i * t1, j * t2);
			if (damage >= h) {
				ans = min(ans, t);
			} else {
				res[damage] = min(res[damage], t);
			}
			damage += p1 + p2 - s;
			t = max((i + 1) * t1, (j + 1) * t2);
			if (damage >= h) {
				ans = min(ans, t);
			} else {
				cost[damage] = min(cost[damage], t);
				res[damage] = min(res[damage], t);
			}
		}
	}
	for (int i = h - 2; i >= 0; i--) {
		res[i] = min(res[i], res[i + 1]);
	}
	vector<LL> tm(h + 1, lnf);
	tm[0] = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 1; j < h && i + j <= h; j++) {
			tm[i + j] = min(tm[i + j], tm[i] + cost[j]);
		}
	}
	for (int i = 1; i <= h; i++) {
		ans = min(ans, tm[i] + res[h - i]);
	}
	printf("%lld\n", ans);
    return 0;
}