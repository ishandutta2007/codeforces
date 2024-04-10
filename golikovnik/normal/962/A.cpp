#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0); cout.precision(12); cout << fixed;
	int n;
	cin >> n;
	vector<int> a(n);
	for (int &x: a) cin >> x;
	int s = accumulate(all(a), 0);
	int cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i];
		if (cur * 2 >= s) {
			cout << i + 1 << "\n";
			break;
		}
	}
	return 0;
}