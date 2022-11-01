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
	int m;
	cin >> m;
	vector <int> b(m);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int ita = 0, itb = 0, cnt = 0;
	while (ita < n && itb < m) {
		if (abs(a[ita] - b[itb]) <= 1) {
			cnt++;
			ita++;
			itb++;
			continue;
		}
		if (a[ita] < b[itb]) {
			ita++;
			continue;
		}
		itb++;
	}
	cout << cnt;
	return 0;
}