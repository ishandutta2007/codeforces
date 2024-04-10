#include <iostream>
#include <vector>

using namespace std;

int main() {
	int q;
	cin >> q;
	while (q--) {
		int n;
		cin >> n;
		vector <bool> used(n);
		vector <int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			used[(i + a[i] % n + n) % n] = true;
		}
		bool tf = true;
		for (int i = 0; i < n; i++)
			if (!used[i])
				tf = false;
		if (tf) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}