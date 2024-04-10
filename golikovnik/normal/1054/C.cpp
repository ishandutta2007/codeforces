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
	vector<int> l(n), r(n);
	for (int &x: l) cin >> x;
	for (int &x: r) cin >> x;
	vector<int> put(n);
	vector<int> ldid(n);
	vector<int> rdid(n);
	int need_put = n;
	int cur_max = n;
	while (need_put) {
		bool ok = 0;
		for (int i = 0; i < n; ++i) {
			int real_l = l[i] - ldid[i];
			int real_r = r[i] - rdid[i];
			if (!real_l && !real_r && !put[i]) {
				ok = 1;
				put[i] = cur_max;
				--need_put;
			}
		}
		int did = 0;
		for (int i = 0; i < n; ++i) {
			ldid[i] = did;
			did += (put[i] > 0);
		}
		did = 0;
		for (int i = n - 1; i >= 0; --i) {
			rdid[i] = did;
			did += (put[i] > 0);
		}
		if (!ok) {
			cout << "NO\n";
			return 0;
		}
		--cur_max;
	}
	cout << "YES\n";
	for (int x: put) {
		cout << x << " ";
	}
	cout << "\n";
	return 0;
}