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
		vector<int> ones;
		for (int i = 0; i < n; ++i) {
			if (a[i] != 0) {
				ones.push_back(i);
			}
		}
		if (ones.size() % 2 != 0) {
			cout << -1 << '\n';
			continue;
		}
		vector<pair<int, int>> answer;
		for (int j = 0; j < ones.size(); j += 2) {
			int x = ones[j];
			int y = ones[j + 1];
			if ((x + y) % 2 == 0) {
				if (a[x] == a[y]) {
					answer.emplace_back(x, x);
					answer.emplace_back(x + 1, y);
				} else {
					answer.emplace_back(x, y);
				}
			} else {
				if (a[x] == a[y]) {
					answer.emplace_back(x, y);
				} else {
					answer.emplace_back(x, x);
					answer.emplace_back(x + 1, y);
				}
			}
		}
		vector<pair<int, int>> kek;
		if (answer.empty()) {
			kek.emplace_back(0, n - 1);
		}
		int l = 0;
		for (auto& now : answer) {
			if (l < now.first) {
				kek.emplace_back(l, now.first - 1);
			}
			l = now.second + 1;
			kek.push_back(now);
		}
		if (kek.back().second < n - 1) {
			kek.emplace_back(kek.back().second + 1, n - 1);
		}
		cout << kek.size() << '\n';
		for (auto& now : kek) {
			cout << now.first + 1 << ' ' << now.second + 1 << '\n';
		}
	}
	return 0;
}