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
		bool tf = false;
		for (int it = 1; it <= 1023; it++) {
			for (int i = 0; i < n; i++)
				b[i] = (a[i] ^ it);
			sort(b.begin(), b.end());
			tf = true;
			for (int i = 0; i < n; i++)
				if (b[i] != a[i])
					tf = false;
			if (tf) {
				cout << it << '\n';
				break;
			}
		}
		if (!tf) cout << "-1\n";
	}
	return 0;
}