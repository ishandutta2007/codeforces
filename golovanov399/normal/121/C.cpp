#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

bool isLucky(int n) {
	while (n) {
		if (n % 10 == 4 || n % 10 == 7) {
			// pass
		} else {
			return false;
		}
		n /= 10;
	}
	return true;
}

int main() {
	int n = nxt(), k = nxt();
	long long m = 1, mfact = 1;
	while (mfact < k) {
		++m;
		mfact *= m;
	}

	vector<int> lucky;
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

	if (m > n) {
		puts("-1");
		return 0;
	}

	int ans = 0;
	for (int x : lucky) {
		if (x <= n - m) {
			ans += 1;
		}
	}

	vector<int> perm(m);
	vector<int> nums;
	for (int i = 0; i < m; ++i) {
		nums.push_back(n - m + 1 + i);
	}
	for (int i = m; i > 0; --i) {
		mfact /= i;
		int idx = (k - 1) / mfact;
		perm[m - i] = nums[idx];
		k -= mfact * idx;
		nums.erase(nums.begin() + idx);
	}

	for (int i = 0; i < m; ++i) {
		if (isLucky(n - m + 1 + i) && isLucky(perm[i])) {
			++ans;
		}
	}

	printf("%d\n", ans);

	return 0;
}