#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		int ch = 0;
		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			x = abs(x);
			if (!x) cout << x;
			else cout << (i & 1 ? -x : x);
			cout << ' ';
		}
		cout << '\n';
	}
}