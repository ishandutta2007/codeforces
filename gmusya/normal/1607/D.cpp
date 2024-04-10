#include <iostream>
#include <vector>
#include <algorithm>

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
		vector<char> colour(n);
		for (int i = 0; i < n; ++i) {
			cin >> colour[i];
		}
		vector<int> blue, red;
		for (int i = 0; i < n; ++i) {
			if (colour[i] == 'R') {
				red.push_back(a[i]);
			} else {
				blue.push_back(a[i]);
			}
		}
		bool flag = true;
		sort(blue.begin(), blue.end());
		int size = static_cast<int>(blue.size());
		for (int i = 0; i < blue.size(); ++i) {
			if (blue[i] <= i) {
				flag = false;
			}
		}
		sort(red.begin(), red.end());
		for (int i = 0; i < red.size(); ++i) {
			if (red[i] - size >= i + 2) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
	return 0;
}