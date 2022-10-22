#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		long long ans = 1ll * (n + 1) * n / 2;
		int now = 1;
		while (now <= n) {
			ans -= now * 2, now *= 2;
		}
		cout << ans << endl;
	}
	return 0;
}