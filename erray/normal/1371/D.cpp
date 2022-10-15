#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		if (k % n == 0) cout << 0;
		else cout << 2;
		cout << '\n';
		vector<string> gr(n, string(n, '0'));
		for (int i = 0; i < n; ++i) {
			int sn = k / n + (k % n > i);
			for (int j = i; sn; --sn, (++j) %= n) gr[i][j] = '1';
		}
		for (string el : gr) cout << el << '\n';
	}
}