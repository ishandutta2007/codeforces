#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		map <int, int> m;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			m[a[i]] = 1;
		}
		int cnt = 0;
		for (auto &now : m)
			now.second = cnt++;
		for (int i = 0; i < n; i++)
			a[i] = m[a[i]];
		vector <int> p(n);
		for (int i = 0; i < n; i++)
			p[a[i]] = i;
		vector <int> dp(n);
		dp[0] = 1;
		for (int i = 1; i < n; i++) {
			if (p[i] > p[i - 1]) dp[i] = dp[i - 1] + 1;
			else dp[i] = 1;
		}
		int ma = 1;
		for (auto &now : dp)
			ma = max(now, ma);
		cout << n - ma << '\n';
	}
	return 0;
}