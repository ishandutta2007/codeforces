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

const long long infty = 1000000000000000ll;

/*input
5
7 3
1 1 1 2 1 3 1
5 1
5 5 5 5 5
4 2
1 3 3 7
2 0
4 2
9 2
1 10 10 1 10 2 7 10 3

*/


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n, k;
		cin >> n >> k;
		long long a[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		long long tt = 0;
		sort(a, a + n);

		for (int i = 0; i < k; ++i) {
			tt += a[n - 2 * k + i] / a[n - k + i];
		}

		for (int i = 0; i < n - 2 * k; ++i) {
			tt += a[i];
		}

		cout << tt << "\n";
	}
}