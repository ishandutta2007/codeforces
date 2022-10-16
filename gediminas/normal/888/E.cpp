#include <bits/stdc++.h>

using namespace std;
/*input
4 4
5 2 4 1
*/
/*input
3 20
199 41 299
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	long long n, m;
	cin >> n >> m;
	int nn = n / 2;
	set<long long> a = {0};

	for (int i = 0; i < nn; ++i) {
		long long x;
		cin >> x;
		auto aa = a;

		for (auto &&j : aa) {
			a.insert((j + x) % m);
		}
	}

	set<long long> b = {0};
	long long ma = 0;

	for (int i = nn; i < n; ++i) {
		long long x;
		cin >> x;
		auto aa = b;

		for (auto &&j : aa) {
			b.insert((j + x) % m);
			ma = max(ma, (j + x) % m);
		}
	}


	for (auto &&i : a) {
		auto it = b.upper_bound(m - i - 1);

		if (it != b.begin()) {
			it--;
		}

		if (it != b.end()) {
			ma = max(ma, i + *it);
		}

		ma = max(ma, i);
	}

	cout << ma;
}