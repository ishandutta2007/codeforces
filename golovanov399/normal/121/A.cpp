#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	vector<long long> lucky;
	for (int len = 1; len <= 9; ++len) {
		for (int mask = 0; mask < (1 << len); ++mask) {
			int num = 0;
			int cur = 1;
			for (int i = 0; i < len; ++i) {
				if (mask & (1 << i)) {
					num += 3 * cur;
				}
				num += 4 * cur;
				cur *= 10;
			}
			lucky.push_back(num);
		}
	}
	lucky.push_back(4444444444ll);

	int l = nxt(), r = nxt();
	long long ans = 0;
	for (long long x : lucky) {
		if (x < l) {
			continue;
		}
		if (x >= r) {
			ans += 1ll * (r - l + 1) * x;
			break;
		} else {
			ans += 1ll * x * (x - l + 1);
			l = x + 1;
		}
	}

	cout << ans << "\n";

	return 0;
}