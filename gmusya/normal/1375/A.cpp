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
		for (int i = 0; i < n; i++) {
			if (i % 2) cout << abs(a[i]) << ' ';
			else cout << -abs(a[i]) << ' ';
		}
		cout << '\n';
	}
	return 0;
}