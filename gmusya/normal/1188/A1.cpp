#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector <int> d(n);
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		d[u]++, d[v]++;
	}
	for (int i = 0; i < n; i++) 
		if (d[i] == 2) {
			cout << "NO";
			return 0;
	}
	cout << "YES";
	return 0;
}