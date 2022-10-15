#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	static int d[5000][5000] = {}, p[5000][5000] = {};
	for (int i = 0; i < n; i++) {
		d[i][i] = p[i][i] = v[i];
	}
	for (int i = n-1; i >= 0; i--) {
		for (int j = i+1; j < n; j++) {
			d[i][j] = d[i+1][j] ^ d[i][j-1];
			p[i][j] = d[i][j];
			p[i][j] = max(p[i][j], max(p[i+1][j], p[i][j-1]));
		}
	}
	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r; l--; r--;
		cout << p[l][r] << "\n";
	}
	return 0;
}