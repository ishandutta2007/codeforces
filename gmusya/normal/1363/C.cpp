#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		x--;
		vector <int> deg(n);
		for (int i = 1; i < n; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			deg[u]++, deg[v]++;
		}
		if (deg[x] <= 1) {
			cout << "Ayush\n";
			continue;
		}
		if (n % 2 == 1) cout << "Ashish\n";
		else cout << "Ayush\n";
	}
	return 0;
}