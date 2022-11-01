#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(n), ans(m);
	vector <pair <int, int>> b(m);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < m; i++)
		cin >> b[i].first;
	for (int i = 0; i < m; i++)
		b[i].second = i;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int uka = 0, ukb = 0;
	while (ukb < m) {
		if (uka == n) {
			ans[b[ukb].second] = n;
			ukb++;
			continue;
		}
		if (b[ukb].first < a[uka]) {
			ans[b[ukb].second] = uka;
			ukb++;
			continue;
		}
		if (b[ukb].first >= a[uka])
			uka++;
	}
	for (auto now : ans)
		cout << now << " ";
	return 0;
}