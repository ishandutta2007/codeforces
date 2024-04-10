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
7
18
63
73
91
438
122690412
31

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long n;
		cin >> n;
		bool x = false;

		for (int i = 2; ; ++i) {
			if (gcd((n - i - 1), i) == 1) {
				cout << i << " " << n - i - 1 << " 1\n";
				x = true;
				break;
			}
			else if (gcd((n - i - 2), i) == 2) {
				cout << i << " " << n - i - 2 << " 2\n";
				x = true;
				break;
			}
		}

		if (x) {
			continue;
		}
		else {
			abort();
		}
	}

}