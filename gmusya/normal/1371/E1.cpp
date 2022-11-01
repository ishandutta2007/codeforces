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
	for (int x = 1; x <= 2000; x++) {
		bool tf = true;
		for (int i = 0; i + p - 1 < n; i++)
			if (x + i >= a[i + p - 1]) tf = false;
		for (int i = 0; i < n; i++)
			if (x + i < a[i])
				tf = false;
		if (tf) ans.push_back(x);
	}
	cout << ans.size() << '\n';
	for (auto & now : ans)
		cout << now << ' ';
	return 0;
}