#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	int ans = 0;
	for (int it = 0; it < m; ++it) {
		int c;
		cin >> c;
		--c;
		++a[c];
		bool ok = 1;
		for (int j = 0; j < n; ++j) {
			ok &= (a[j] > 0);
		}
		if (ok) {
			++ans;
			for (int j = 0; j < n; ++j) {
				--a[j];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}