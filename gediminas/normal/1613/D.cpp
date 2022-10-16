#include <bits/stdc++.h>

using namespace std;

const long long maxn = 500010;
long long pow2[maxn] = {};
long long mod = 998244353;
#define MOD(x) ((x)%mod)


/*input
5
2
0 2
3
0 2 1
2
1 0
5
0 0 0 0 0
4
0 1 2 3

*/
/*input
1
30
0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
*/
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	pow2[0] = 1;

	for (int i = 1; i < maxn; ++i) {
		pow2[i] = MOD(pow2[i - 1] * 2);
	}

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		vector<int> a(n);

		for (auto &&i : a) {
			cin >> i;
		}

		long long ger[n + 1] = {};
		long long blog[n + 4] = {};

		long long ans = 0;

		for (int i = 0; i < n; ++i) {
			ans += blog[a[i]];
			ans += blog[a[i] + 2];
			ans += ger[a[i]];

			if (a[i] == 0) {
				ans += 1;
				ger[a[i]] = MOD(2 * ger[a[i]] + 1);
			}
			else if (a[i] == 1) {
				ans += ger[0] + 1;
				ger[1] = MOD(2 * ger[1] + ger[0]);
				blog[1] = MOD(blog[1] * 2 + 1);
			}
			else {
				ans += ger[a[i] - 1];
				ans += ger[a[i] - 2];

				ger[a[i]] = MOD(2 * ger[a[i]] + ger[a[i] - 1]);
				blog[a[i]] = MOD(2 * blog[a[i]] + ger[a[i] - 2]);
			}

			blog[a[i] + 2] = MOD(2 * blog[a[i] + 2]);
			ans = MOD(ans);
		}

		cout << ans << "\n";
	}
}