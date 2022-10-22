#include <bits/stdc++.h>
using namespace std;

long long get_num(int sum) {
	if (sum < 9) return sum;
	sum -= 8;
	long long pw = 10, ans = 8;
	while (sum > 9) {
		sum -= 9, ans += pw * 9, pw *= 10;
	}
	ans += pw * sum;
	return ans;
}

int main () {
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		int full = (1 << 4) - 1;
		long long ans = 5000000000000000000;
		for (int i = 0; i < 10; i++) {
			int sss = 0;
			for (int j = 0; j <= k; j++) {
				sss += (i + j) % 10;
			}
			for (int j = 0; j < 17 && i + k < 10 || j < 1; j++) {
				int sum = sss + min(10 - i, k + 1) * j * 9;
				if (sum > n) break;
				sum = n - sum - max(0, i + k - 10 + 1);
				if (sum % (k + 1) != 0) continue;
				sum /= k + 1;
				long long num = get_num(sum);
				for (int k = 0; k < j; k++) {
					num = num * 10 + 9;
				}
				num = num * 10 + i;
				ans = min(ans, num);
			}
		}
		if (ans == 5000000000000000000) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}