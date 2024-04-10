#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		if (n % 2 != 0) {
			cout << -1 << '\n';
			continue;
		}
		vector<pair<int, int>> answer;
		for (int i = 0; i < n; i += 2) {
			if (a[i] == a[i + 1]) {
				answer.emplace_back(i, i + 1);
			} else {
				answer.emplace_back(i, i);
				answer.emplace_back(i + 1, i + 1);
			}
		}
		cout << answer.size() << '\n';
		for (auto& now : answer) {
			cout << now.first + 1 << ' ' << now.second + 1 << '\n';
		}
	}
	return 0;
}