#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int m, n;
	cin >> m >> n;
	auto query = [](int x) {
		cout << x << "\n" << flush;
		int res;
		cin >> res;
		if (!res) exit(0);
		return res;
	};
	vector<int> type(n);
	for (int i = 0; i < n; ++i) {
		type[i] = query(1);
	}
	int l = 1, r = m;
	for (int i = 0; l < r; i = (i + 1) % n) {
		int mid = (l + r) >> 1;
		int res = query(mid);
		if (type[i] < 0) res *= -1;
		if (res > 0) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	query(l);
	return 0;	
}