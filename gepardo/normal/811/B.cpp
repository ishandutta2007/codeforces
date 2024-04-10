#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < k; i++) {
		int l, r, x; cin >> l >> r >> x; l--; r--; x--;
		vector<int> w = v;
		vector<int> c(n+1, 0);
		for (int j = l; j <= r; j++) {
			c[v[j]]++;
		}
		int p = l;
		for (int j = 0; j <= n; j++) {
			for (int k = 0; k < c[j]; k++) {
				w[p++] = j;
			}
		}
		cout << ((v[x] == w[x]) ? "Yes" : "No") << "\n";
	}
	return 0;
}