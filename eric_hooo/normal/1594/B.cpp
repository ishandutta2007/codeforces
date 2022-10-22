#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int main() {
	int T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		long long ans = 0, pw = 1;
		for (int it = 0; it < 30; it++) {
			if (k >> it & 1) ans = (ans + pw) % mod;
			pw = pw * n % mod;
		}
		cout << ans << endl;
	}
	return 0;
}