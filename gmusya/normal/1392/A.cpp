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
		if (a[0] == a[n - 1])
			cout << n << '\n';
		else
			cout << 1 << '\n';
	}
	return 0;
}