#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 0; i < n; i++)
			cin >> b[i];
		bool canp1 = false, canm1 = false;
		bool tf = true;
		for (int i = 0; i < n; i++) {
			if (a[i] > b[i] && !canm1) tf = false;
			if (a[i] < b[i] && !canp1) tf = false;
			if (a[i] > 0) canp1 = true;
			if (a[i] < 0) canm1 = true;
		}
		if (tf) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}