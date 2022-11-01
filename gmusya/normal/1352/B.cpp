#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		vector <int> a(k);
		for (int i = 0; i < k - 1; i++)
			a[i] = 1;
		a[k - 1] = n - (k - 1);
		if (a[0] % 2 == a[k - 1] % 2 && a[k - 1] > 0) {
			cout << "YES" << endl;
			for (int i = 0; i < k; i++)
				cout << a[i] << ' ';
			cout << endl;
			continue;
		}
		for (int i = 0; i < k - 1; i++)
			a[i] = 2;
		a[k - 1] = (n - 2 * (k - 1));
		if (a[0] % 2 == a[k - 1] % 2 && a[k - 1] > 0) {
			cout << "YES" << endl;
			for (int i = 0; i < k; i++)
				cout << a[i] << ' ';
			cout << endl;
			continue;
		}
		cout << "NO" << endl;
	}
	return 0;
}