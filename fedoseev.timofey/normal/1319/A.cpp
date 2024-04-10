#include  <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
	int n;
	cin >> n;
	int f = 0, s = 0;
	vector <int> r(n), b(n);
	for (int i = 0; i < n; ++i) cin >> r[i];
	for (int i = 0; i < n; ++i) cin >> b[i];
	for (int i = 0; i < n; ++i) {
	 	if (r[i] != b[i]) {
	 	 	if (r[i]) ++f;
	 	 	if (b[i]) ++s;
		}
	}
	if (f == 0) {
	  cout << "-1\n";
	  return;
	} else {
	 	cout << (s + 1 + f - 1) / f << '\n';
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	#endif
	int t = 1;
	// cin >> t;
	while (t--) {
		solve();
	}	
}