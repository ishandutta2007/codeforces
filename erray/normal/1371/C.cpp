#include<bits/stdc++.h>

using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--) {
		long long a, b, n, m;
		cin >> a >> b >> n >> m;
		bool ok = true;
		if (a + b < n + m) ok = false;
		if (a < b) swap(a, b);
		if (b < m) ok = false;
		cout << (ok ? "Yes" : "No") << '\n';
	}
}