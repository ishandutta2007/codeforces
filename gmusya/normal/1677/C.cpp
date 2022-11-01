#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int& x: a) {
			cin >> x;
			--x;
		}
		vector<int> b(n);
		for (int& x: b) {
			cin >> x;
			--x;
		}
		vector<int> p(n);
		for (int i = 0; i < n; ++i) {
			p[a[i]] = i;
		}
		for (int i = 0; i < n; ++i) {
			a[i] = p[a[i]];
			b[i] = p[b[i]];
		}
		vector<bool> used(n);
		int odd = 0;
		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			int x = i;
			used[x] = true;
			int cnt = 1;
			while (!used[b[x]]) {
				x = b[x];
				used[x] = true;
				cnt += 1;
			}
			odd += cnt % 2;
		}
		ll big = 0;
		ll small = 0;
		for (int i = 1; i <= (n - odd) / 2; ++i) {
			small += i;
		}
		for (int i = (n + odd) / 2 + 1; i <= n; ++i) {
			big += i;
		}
		cout << 2 * (big - small) << '\n';
	}
	return 0;
}

/*
1
6
1 2 3 4 5 6
2 3 1 6 4 5
 */