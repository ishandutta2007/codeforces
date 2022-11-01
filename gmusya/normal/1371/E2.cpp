#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, p;
	cin >> n >> p;
	vector <int> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a.begin(), a.end());

	vector <int> ans;
	int need = -1e9;
	int toomuch = 1e9;
	for (int i = 0; i < n; i++)
		need = max(need, a[i] - i);
	for (int i = 0; i + p - 1 < n; i++)
		toomuch = min(toomuch, a[i + p - 1] - i);
	for (int i = need; i < toomuch; i++)
		ans.push_back(i);
	cout << ans.size() << '\n';
	for (auto & now : ans)
		cout << now << ' ';
	return 0;
}