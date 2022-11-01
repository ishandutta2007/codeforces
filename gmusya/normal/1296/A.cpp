#include <iostream>
#include <vector>

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
		int cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (a[i] % 2);
		if (cnt == n) {
			if (n % 2)
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
			continue;
		}
		if (cnt == 0) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
	}
	return 0;
}