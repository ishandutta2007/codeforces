#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int n; cin >> n;
	vector<int> a(n); for (int &x: a) {cin >> x; --x;}	
	int ans = 0;
	vector<bool> used(n);
	for (int i = 0; i < n; ++i) {
		int len = 0;
		int cur = i;
		while (!used[cur]) {
			used[cur] = 1;
			++len;
			cur = a[cur];
		}
		if (len) {
			ans += (len - 1);
			ans %= 2;
		}
	}
	n %= 2;
	cout << ((ans == n) ? "Petr" : "Um_nik") << "\n";
	return 0;
}