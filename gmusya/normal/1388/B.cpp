#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			if (i * 4 < n)
				a[i] = 8;
			else a[i] = 9;
		}
		for (int i = n - 1; i >= 0; i--)
			cout << a[i];
		cout << '\n';
	}
	return 0;
}