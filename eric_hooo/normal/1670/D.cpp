#include <bits/stdc++.h>
using namespace std;

long long Solve(long long n) {
	long long x = n / 3 + (n % 3 > 0), y = n / 3 + (n % 3 > 1), z = n / 3;
	long long ans = x * (y + z) + y * (x + z) + z * (x + y);
	// cerr << "          ans:" << ans << endl;
	return ans;
	if (x == y && z) z--, ans += x, y--;
	long long t = min(x, y);
	long long s = t - z / 2;
	ans += (s + 1 + t) * (z / 2) / 2 * 2 * 3;
	if (z & 1) ans += s * 3;
	return ans;
}

int main() {
	// cout << " !:" << Solve(3) << endl;
	// return 0;
	int T; scanf("%d", &T);
	while (T--) {
		long long n; cin >> n;
		long long l = 2, r = 100000000;
		while (l < r) {
			long long mid = l + r >> 1;
			if (Solve(mid) < n) l = mid + 1;
			else r = mid;
		}
		cout << l << endl;
	}
	return 0;
}