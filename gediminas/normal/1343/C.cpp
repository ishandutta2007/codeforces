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
4
5
1 2 3 -1 -2
4
-1 -2 -1 -3
10
-2 8 3 8 -4 -15 5 -2 -3 1
6
1 -1000000000 1 -1000000000 1 -1000000000
*/
int sgn(long long t) {
	return t > 0 ? 1 : -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		vector<long long> a(n);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long sum = 0;
		long long la = 0;

		for (int i = 0; i < n; ++i) {
			if (i == 0 or sgn(la) != sgn(a[i])) {
				sum += la;
				la = a[i];
			}
			else {
				la = max(la, a[i]);
			}
		}

		sum += la;

		cout << sum << "\n";
	}
}