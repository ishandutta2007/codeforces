#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int n, q;
	cin >> n >> q;
	int LOG = 32;
	vector<int> cnt(LOG + 1);
	function<int(int)> _log = [&] (int x) {
		int res = -1;
		while (x) {
			++res;
			x >>= 1;
		}
		return res;
	};
	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		// cerr << x << " " << _log(x) << "\n";
		++cnt[_log(x)];
	}
	while (q--) {
		int b;
		cin >> b;
		int res = 0;
		for (int deg = LOG; deg >= 0; --deg) {
			int each = 1LL << deg;
			int take = min(cnt[deg], b / each);
			res += take;
			b -= take * each;
		}
		if (b) res = -1;
		cout << res << "\n";
	}
	return 0;	
}