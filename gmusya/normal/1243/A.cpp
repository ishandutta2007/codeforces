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
		sort(a.begin(), a.end());
		reverse(a.begin(), a.end());
		int m = 0;
		for (int i = 0; i < n; i++)
			m = max(min(a[i], i + 1), m);
		cout << min(m, n) << endl;
	}
	return 0;
}