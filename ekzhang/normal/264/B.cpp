#include <bits/stdc++.h>
using namespace std;

#define MAXN 100000

int N;
int nums[MAXN];
int dp[MAXN + 1];
int dp2[MAXN + 1];

int gcd(int a, int b) {
	return b == 0 ? a : gcd(b, a % b);
}

vector<int> factorize(int n) {
	vector<int> ret;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			ret.push_back(i);
			n /= i;
		}
		while (n % i == 0) {
			n /= i;
		}
	}
	if (n != 1) {
		ret.push_back(n);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> nums[i];
	}

	if (N == 1 && nums[0] == 1) {
		cout << 1 << endl;
		return 0;
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		vector<int> factors = factorize(nums[i]);
		for (int j : factors) {
			dp[nums[i]] = max(dp[nums[i]], dp2[j] + 1);
		}
		for (int j : factors) {
			dp2[j] = dp[nums[i]];
		}
		ans = max(ans, dp[nums[i]]);
	}

	cout << ans << endl;
	return 0;
}