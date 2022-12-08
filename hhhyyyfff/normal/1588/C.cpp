#include <bits/stdc++.h>

using namespace std;

map<long long, int> mp;
int t, n, ai, opt;
long long delta, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		mp.clear();
		opt = 1;
		delta = 0;
		scanf("%d", &n);
		ans = 0;
		while (n--) {
			scanf("%d", &ai);
			if (!ai) ++ans;
			if (opt == 1) {
				while (!mp.empty() && mp.rbegin()->first + delta > ai)
					mp.erase(--mp.end());
			} else {
				while (!mp.empty() && -mp.begin()->first + delta > ai)
					mp.erase(mp.begin());
			}
			ans += opt == 1 ? mp[ai - delta] : mp[delta - ai];
			opt = -opt, delta = -delta;
			delta += ai;
			++mp[opt * (ai - delta)];
		}
		printf("%lld\n", ans);
	}
	return 0;
}