#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, d;
	cin >> n >> m >> d;
	vector <pair <int, int>> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	vector <int> b(n);
	int cnt = 1;
	b[0] = 1;
	for (int i = 1; i < n; i++) {
		if (a[i].first - d <= a[i - cnt].first) {
			cnt++;
			b[i] = cnt;
			continue;
		}
		b[i] = b[i - cnt];
	}
	vector <pair <int, int>> c(n);
	for (int i = 0; i < n; i++) {
		c[i].first = a[i].second;
		c[i].second = b[i];
	}
	sort(c.begin(), c.end());
	int ma = 0;
	for (auto now : c)
		ma = max(ma, now.second);
	cout << ma << endl;
	for (auto now : c)
		cout << now.second << " ";
	return 0;
}