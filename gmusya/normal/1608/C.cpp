#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < n; ++i) {
			cin >> b[i];
		}
		vector<int> p(n);
		iota(p.begin(), p.end(), 0);
		sort(p.begin(), p.end(), [&](int i, int j) {
			return a[i] < a[j];
		});
		vector<int> pref_max(n), suf_min(n);
		pref_max[0] = b[p[0]];
		for (int i = 1; i < n; ++i) {
			pref_max[i] = max(pref_max[i - 1], b[p[i]]);
		}
		int L = 0, R = n - 1;
		while (L != R) {
			int M = (L + R) / 2;
			int max_b = pref_max[M];
			for (int j = M + 1; j < n; ++j) {
				if (max_b > b[p[j]]) {
					max_b = pref_max[j];
				}
			}
			if (max_b == pref_max[n - 1]) {
				R = M;
			} else {
				L = M + 1;
			}
		}
		vector<bool> can(n);
		for (int i = L; i < n; ++i) {
			can[p[i]] = true;
		}
		for (int i = 0; i < n; ++i) {
			if (can[i]) {
				cout << 1;
			} else {
				cout << 0;
			}
		}
		cout << '\n';
	}
	return 0;
}