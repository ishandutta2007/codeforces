#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL tot, M = 99999999999808LL;
char str[100];

bool query(LL x) {
	x = min(x, (LL)1e14);
	printf("? %lld\n", x);
	fflush(stdout);
	scanf("%s", str);
//	str[0] = x <= M ? 'L' : 'F';
	if (str[0] == 'L') {
		tot += x;
		return 1;
	} else {
		assert(tot >= x);
		tot -= x;
		return 0;
	}
}

const LL B = 1e14;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		tot = 1;
		LL cur = 1, l, r;
		while (true) {
			if (!query(cur)) {
				r = cur, l = cur >> 1;
				break;
			} else {
				if (cur >= 1e14) {
					l = r = 1e14;
					break;
				}
				cur <<= 1;
			}
		}
		query(l);
		query(l);
		while (l + 1 < r) {
			LL mid = l + max(1ll, (LL)((r - l) * 0.3));
			if (tot >= r * 2) mid = l + max(1ll, (LL)((r - l) * 0.4));
			if (tot >= r * 4) mid = l + max(1ll, (LL)((r - l) * 0.5));
			if (tot >= r * 6) mid = l + max(1ll, (LL)((r - l) * 0.6));
			if (tot < mid) {
				query(l);
				continue;
			}
			if (query(mid)) l = mid;
			else r = mid;
		}
		printf("! %lld\n", l);
		fflush(stdout);
	}
	return 0;
}