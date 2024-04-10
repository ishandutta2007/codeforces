#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		map <int, int> m;
		for (int i = 0; i < n; i++)
			m[a[i]] = 1;
		int cnt = 0;
		for (auto &now : m)
			m[now.first] = cnt++;
		for (int i = 0; i < n; i++)
			a[i] = m[a[i]];
		vector <int> ans;
		for (int i = 0; i < n - 2; i++) {
			int pos = i;
			for (int j = i + 1; j < n; j++)
				if (a[j] < a[pos])
					pos = j;
			while (pos - i >= 2) {
				ans.push_back(pos - 2);
				swap(a[pos], a[pos - 1]);
				swap(a[pos - 1], a[pos - 2]);
				pos -= 2;
			}
			if (pos - i == 1) {
				ans.push_back(pos - 1), ans.push_back(pos - 1);
				swap(a[pos], a[pos - 1]);
				swap(a[pos], a[pos + 1]);
			}
		}
		if (a[n - 2] == n - 1) {
			cout << -1 << '\n';
			continue;
		}
		if (a[n - 1] >= a[n - 2]) {
			cout << ans.size() << '\n';
			for (auto &now : ans)
				cout << now + 1 << ' ';
			cout << '\n';
			continue;
		}
		if (a[n - 3] == a[n - 1]) {
			ans.push_back(n - 3);
			cout << ans.size() << '\n';
			for (auto &now : ans)
				cout << now + 1 << ' ';
			cout << '\n';
			continue;
		}
		int x = n - 1;
		while (a[x] != a[x - 1]) x--;
		while (x != n - 3) {
			ans.push_back(x - 1);
			swap(a[x - 1], a[x + 1]);
			x++;
		}
		ans.push_back(n - 3);
		ans.push_back(n - 4);
		while (x > 1 && a[x] < a[x - 2]) {
			ans.push_back(x - 2);
			ans.push_back(x - 2);
			swap(a[x], a[x - 2]);
			x--;
		}
		cout << ans.size() << '\n';
		for (auto &now : ans)
			cout << now + 1 << ' ';
		cout << '\n';
	}
	return 0;
}