#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, k, s;
	cin >> n >> k >> s;
	if (s < k || s > (n - 1) * k) {
		puts("NO");
		return 0;
	}	
	cout << "YES\n";
	while (k > 2) {
		int delta = (s - k + 2) / 2;
		delta = min(delta, n - 1);
		s -= 2 * delta;
		k -= 2;
		cout << delta + 1 << " " << 1 << " ";
	}
	if (k == 1) {
		cout << s + 1 << "\n";
		return 0;
	}
	if (s <= n)
		cout << s << " " << s - 1 << "\n";
	else
		cout << n << " " << 2 * n - s - 1 << "\n";
	return 0;	
}