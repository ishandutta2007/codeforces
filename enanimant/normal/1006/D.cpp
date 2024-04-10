// July 16, 2018
// http://codeforces.com/contest/1006/problem/D

/*
Cleaner?
*/


#include <bits/stdc++.h>

using namespace std;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif // _DEBUG)


	int n;
	string a, b;
	cin >> n;
	cin >> a >> b;

	int ans = 0;
	for (int i = 0; i < n / 2; i++) {
		int j = n - 1 - i;
		if (a[i] == a[j] && b[i] == b[j] || a[i] == b[i] && a[j] == b[j] || a[i] == b[j] && a[j] == b[i]) {
			continue;
		} else if (a[i] == b[i] || a[i] == b[j] || a[j] == b[i] || a[j] == b[j] || b[i] == b[j]) {
			ans++;
		} else {
			ans += 2;
		}
	}

	if (n % 2 == 1) {
		ans += (a[n / 2] == b[n / 2] ? 0 : 1);
	}

	cout << ans << '\n';

	return 0;
}