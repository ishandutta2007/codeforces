#include <bits/stdc++.h>

using namespace std;
/*input
4
2 5
1 5
3 10
2 4 10
5 3
1 2 4 5 7
4 1000
3 25 64 1337
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		long long h;
		cin >> n >> h;

		vector<int> a(n);

		for (auto &&i : a) {
			cin >> i;
		}

		long long mi = 1, ma = h;

		while (mi < ma) {
			long long mid = (mi + ma) / 2;
			long long d = h;

			for (int i = 0; i < n; ++i) {
				d -= max(0ll, min(min(d, mid), (i != n - 1 ? a[i + 1] - a[i] : h)));
			}

			if (d > 0) {
				mi = mid + 1;
			}
			else {
				ma = mid;
			}
		}

		cout << mi << "\n";
	}
}