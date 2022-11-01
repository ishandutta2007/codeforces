#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		vector <int> ans;
		int n;
		cin >> n;
		ans.push_back(1);
		int sum = 1;
		while (true) {
			if (sum + 2 * ans[ans.size() - 1] >= n) {
				ans.push_back(n - sum);
				break;
			}
			ans.push_back(min(2 * ans[ans.size() - 1], (n - sum) / 2));
			sum += ans[ans.size() - 1];
			continue;
		}
		cout << ans.size() - 1 << '\n';
		for (int i = 1; i < ans.size(); i++)
			cout << ans[i] - ans[i - 1] << ' ';
		cout << '\n';
	}
	return 0;
}