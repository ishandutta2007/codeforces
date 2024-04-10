#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector <int> deg(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		deg[u]++;
		deg[v]++;
	}
	sort(deg.begin(), deg.end());
	if (deg[n - 1] == n - 1 && deg[0] == 1 && deg[n - 2] == 1) {
		cout << "star topology";
		return 0;
	}
	if (deg[0] == 1 && deg[1] == 1 && deg[2] == deg[n - 1]) {
		cout << "bus topology";
		return 0;
	}
	if (deg[0] == 2 && deg[n - 1] == 2) {
		cout << "ring topology";
		return 0;
	}
	cout << "unknown topology";
	return 0;
}