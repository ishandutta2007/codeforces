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
1 2
2 8
4 5
1 5
100000 200000
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		long long a, b;
		cin >> a >> b;

		long long ans = b - a;

		for (long long i = 0; i < 32; ++i) {
			long long c = (1ll << i);
			auto f = [&](long long x) -> long long {
				return x / 2 / c * c + min(x % (2 * c) + 1, c);
			};

			long long u = f(b) - f(a - 1);

			ans = min(ans, u);
		}

		cout << ans << "\n";
	}
}