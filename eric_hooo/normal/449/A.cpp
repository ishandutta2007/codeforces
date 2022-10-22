#include <bits/stdc++.h>
using namespace std;
int main () {
	int n, m, k; cin >> n >> m >> k;
	int x = 1;
	long long ans = -1;
	while (x <= n) {
		int y = k - (x - 1) + 1;
		if (y >= 1 && y <= m) ans = max(ans, 1ll * (n / x) * (m / y));
		x = n / (n / x), y = k - (x - 1) + 1;
		if (y >= 1 && y <= m) ans = max(ans, 1ll * (n / x) * (m / y));
		x++;
	}
	x = 1;
	while (x <= m) {
		int y = k - (x - 1) + 1;
		if (y >= 1 && y <= n) ans = max(ans, 1ll * (n / y) * (m / x));
		x = m / (m / x), y = k - (x - 1) + 1;
		if (y >= 1 && y <= n) ans = max(ans, 1ll * (n / y) * (m / x));
		x++;
	}
	cout << ans << endl;
	return 0;
}