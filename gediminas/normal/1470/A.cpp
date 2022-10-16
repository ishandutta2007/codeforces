#include <bits/stdc++.h>

using namespace std;
/*input
2
5 4
2 3 4 3 2
3 5 12 20
5 5
5 4 3 2 1
10 40 90 160 250
*/
/*input
1
1 1
1
1
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<int> a(n);
		vector<int> b(m);

		for (auto &&i : a) {
			cin >> i;
		}

		for (auto &&j : b) {
			cin >> j;
		}

		sort(a.rbegin(), a.rend());
		long long ans = 0;
		int pr = 0;

		for (auto &&i : a) {
			if (pr < i and pr < m) {
				ans += b[pr];
				pr++;
			}
			else {
				ans += b[i - 1];
			}
		}

		cout << ans << endl;
	}
}