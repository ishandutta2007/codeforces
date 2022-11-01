#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	vector <int> ans(t);
	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int j = 0; j < n; j++) cin >> a[j];
		sort(a.begin(), a.end());
		ans[i] = min(a[n - 2] - 1, n - 2);
	}
	for (int i = 0; i < t; i++) cout << ans[i] << endl;
	return 0;
}