#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	vector <pair <int, int>> b;
	pair <int, int> x = { 0, 0 };
	for (int i = 1; i < n; i++) {
		if (a[i] > a[i - 1])
			x.second = i;
		else {
			b.push_back(x);
			x.first = x.second = i;
		}
	}
	b.push_back(x);
	int ma = 0;
	for (auto now : b)
		ma = max(ma, now.second - now.first + 2);
	for (int i = 0; i < b.size() - 1; i++)
		if ((b[i].second > 0 && a[b[i + 1].first] - 1 > a[b[i].second - 1]) || (b[i + 1].first != n - 1 && a[b[i].second] + 1 < a[b[i + 1].first + 1]))
			ma = max(ma, b[i + 1].second - b[i].first + 1);
	cout << min(ma, n);
	return 0;
}