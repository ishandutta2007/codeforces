#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int sum = 0;
		int n, k;
		cin >> n >> k;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		sort(a.begin(), a.end());
		for (int i = k; i < n; i++)
			sum += a[i];
		for (int i = 0; i < k; i++)
			b.push_back(a[i]);
		sort(b.begin(), b.end());
		reverse(b.begin(), b.end());
		for (int i = 0; i < k; i++)
			sum += b[i];
		cout << sum << '\n';
	}
	return 0;
}