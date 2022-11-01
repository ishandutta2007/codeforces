#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <char> c(n);
		for (int i = 0; i < n; i++)
			cin >> c[i];
		sort(c.begin(), c.end());
		if (c[0] != c[k - 1]) {
			cout << c[k - 1] << '\n';
			continue;
		}
		vector <char> ans;
		ans.push_back(c[0]);
		if (c[k] == c[n - 1]) {
			for (int i = k; i < n; i += k)
				ans.push_back(c[i]);
		}
		else for (int i = k; i < n; i++)
			ans.push_back(c[i]);
		for (int i = 0; i < ans.size(); i++)
			cout << ans[i];
		cout << '\n';
	}
	return 0;
}