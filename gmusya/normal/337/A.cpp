#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> a(m);
	for (int i = 0; i < m; i++)
		cin >> a[i];
	sort(a.begin(), a.end());
	int ans = 50000;
	for (int i = 0; i < m - n + 1; i++)
		ans = min(ans, a[i + n - 1] - a[i]);
	cout << ans;
	return 0;
}