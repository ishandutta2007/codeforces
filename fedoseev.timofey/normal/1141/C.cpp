#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n - 1);
    for (int i = 0; i < n - 1; ++i) cin >> a[i];
    vector <int> p(n);
	for (int i = 0; i + 1 < n; ++i) p[i + 1] = p[i] + a[i];
	int mn = 1e18;
	for (int i = 0; i < n; ++i) mn = min(mn, p[i]);
	for (int i = 0; i < n; ++i) p[i] -= mn;
	set <int> have;
	for (int i = 0; i < n; ++i) {
		if (p[i] >= n) {
			cout << "-1\n";
			return 0;
		}
		have.insert(p[i]);
	}
	if ((int)have.size() != n) {
		cout << "-1\n";
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		cout << p[i] + 1 << ' ';
	}
}