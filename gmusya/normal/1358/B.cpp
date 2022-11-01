#include <iostream>
#include <vector>
#include <algorithm>

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
		int ans = 1;
		sort(a.begin(), a.end());
		for (int i = n - 1; i >= 0; i--)
			if (a[i] <= i + 1) {
				ans = i + 2;
				break;
			}
		cout << ans << '\n';
	}
	return 0;
}