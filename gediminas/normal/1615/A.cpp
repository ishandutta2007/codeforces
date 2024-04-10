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
3
3
10 10 10
4
3 2 1 2
5
1 2 3 1 5
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		long long s = 0;

		for (int i = 0; i < n; ++i) {
			long long a;
			cin >> a;
			s += a;
		}

		cout << (s % n > 0) << "\n";
	}
}