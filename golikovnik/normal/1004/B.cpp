#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		a[i] = make_pair(l, r);
	}
	for (int i = 0; i < n; ++i) {
		cout << (i & 1) << "";
	}
	cout << "\n";
	return 0;	
}