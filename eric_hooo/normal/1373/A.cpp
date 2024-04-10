#include <bits/stdc++.h>
using namespace std;
int main () {
	int T; cin >> T;
	while (T--) {
		long long a, b, c; cin >> a >> b >> c;
		if (a * b <= c) {
			cout << 1 << " " << -1 << endl;
			continue;
		}
		if (a >= c) cout << -1 << " ";
		else cout << 1 << " ";
		cout << b << endl;
	}
	return 0;
}