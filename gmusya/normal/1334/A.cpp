#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> p(n), c(n);
		bool tf = true;
		for (int i = 0; i < n; i++) {
			cin >> p[i] >> c[i];
			if (c[i] > p[i]) tf = false;
		}
		for (int i = 0; i < n - 1; i++) {
			int x = p[i + 1] - p[i];
			int y = c[i + 1] - c[i];
			if (y > x || x < 0 || y < 0) tf = false;
		}
		if (!tf) cout << "NO\n";
		else cout << "YES\n";
	}
	return 0;
}