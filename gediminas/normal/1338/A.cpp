#include <bits/stdc++.h>

using namespace std;
/*input
3
4
1 7 6 5
5
1 2 3 4 5
2
0 -4

*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		vector<long long> a(n);

		for (auto &&i : a) {
			cin >> i;
		}

		long long skirt = 0;
		long long ma = -1000000000;

		for (auto &&i : a) {
			ma = max(ma, i);
			skirt = max(skirt, abs(ma - i));
		}
		long long ans = 0;
		while (skirt > 0) {
			skirt /= 2;
			ans++;
		}
		cout << ans << "\n";
	}
}