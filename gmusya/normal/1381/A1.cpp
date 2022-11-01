#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			a[i] = c - '0';
		}
		for (int i = 0; i < n; i++) {
			char c;
			cin >> c;
			b[i] = c - '0';
		}
		vector <int> ans;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] == b[i]) continue;
			if (a[0] == b[i]) {
				ans.push_back(0);
				a[0] = 1 - a[0];
			}
			ans.push_back(i);
			reverse(a.begin(), a.begin() + i + 1);
			for (int j = 0; j <= i; j++)
				a[j] = 1 - a[j];
		}
		cout << ans.size() << ' ';
		for (auto &now : ans)
			cout << now + 1 << ' ';
		cout << '\n';
	}
	return 0;
}