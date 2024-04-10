#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	for (int z = 0; z < t; z++) {
		int n;
		cin >> n;
		vector <int> a(n), b(n), c(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < n; i++) cin >> b[i];
		for (int i = 0; i < n; i++) c[i] = b[i] - a[i];
		int l = -1; int r = -1;
		bool tf = true;
		for (int i = 0; i < n; i++) if (c[i] < 0) tf = false;
		for (int i = 0; i < n; i++) {
			if (c[i] != 0) {
				l = i;
				break;
			}
		}
		for (int i = n - 1; i >= 0; i--) {
			if (c[i] != 0) {
				r = i;
				break;
			}
		}
		if (l != -1 && r != -1)
			for (int i = l; i <= r; i++)
				if (c[i] != c[l])
					tf = false;
		if (tf)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}