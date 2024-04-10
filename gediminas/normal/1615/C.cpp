#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
5
5
11010
11010
2
01
11
3
000
101
9
100010111
101101100
9
001011011
011010101
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		string a, b;
		cin >> n >> a >> b;
		string c = b;

		for (int i = 0; i < n; ++i) {
			c[i] = c[i] == '0' ? '1' : '0';
		}

		int ans = a.size() + 1;

		auto f = [&](string x) -> int {
			int s = 0;

			int t[2] = {};

			for (int i = 0; i < x.size(); ++i) {
				if (x[i] != a[i]) {
					s++;
					t[a[i] - '0']++;
				}
			}

			if (t[1] != t[0] and t[1] != t[0] + 1) {
				return a.size() + 2;
			}

			return s;
		};

		if (f(b) % 2 == 0) {
			ans = f(b);
		}

		if (f(c) % 2 == 1) {
			ans = min(ans, f(c));
		}

		if (ans >= a.size() + 1) {
			cout << "-1\n";
			continue;
		}

		cout << ans << "\n";
	}
}