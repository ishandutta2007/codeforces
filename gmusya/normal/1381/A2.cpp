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
		int h = 0;
		bool tf = true;
		int rev = 0;
		vector <int> ans;
		for (int i = n - 1; i >= 0; i--) {
			if (tf) {
				if (a[h + i] == b[i]) continue;
				if (a[h] == b[i]) {
					ans.push_back(0);
					a[h] = 1 - a[h];
					tf = false;
					h = h + i;
					ans.push_back(i);
					continue;
				}
				ans.push_back(i);
				if (i) ans.push_back(i - 1);
				h++;
				continue;
			}
			if (a[h - i] != b[i]) continue;
			if (a[h] != b[i]) {
				ans.push_back(0);
				a[h] = 1 - a[h];
				tf = true;
				h = h - i;
				ans.push_back(i);
				continue;
			}
			ans.push_back(i);
			if (i) ans.push_back(i - 1);
			h--;
		}
		cout << ans.size() << ' ';
		for (auto &now : ans)
			cout << now + 1 << ' ';
		cout << '\n';
	}
	return 0;
}