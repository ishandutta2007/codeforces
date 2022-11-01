#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		++cnt[a[i]];
	}
	while (!cnt.empty()) {
		pair<int, int> now = *cnt.begin();
		cnt.erase(now.first);
		if (now.first >= x) {
			continue;
		}
		if (now.second % (now.first + 1) != 0) {
			cout << "No";
			return 0;
		}
		cnt[now.first + 1] += now.second / (now.first + 1);
	}
	cout << "Yes";
	return 0;
}