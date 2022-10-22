#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long x, y, k; cin >> x >> y >> k;
		long long need = k * y + k;
		need--;
		need = (need + x - 1 - 1) / (x - 1);
		cout << need + k << endl;
	}
	return 0;
}