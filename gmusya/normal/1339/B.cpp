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
		vector <int> b(n);
		int it = 0;
		for (int i = 0; i < n; i += 2, it++)
			b[i] = a[it];
		for (int i = 1, it = n - 1; i < n; i += 2, it--)
			b[i] = a[it];
		reverse(b.begin(), b.end());
		for (auto &now : b)
			cout << now << ' ';
	}
	return 0;
}