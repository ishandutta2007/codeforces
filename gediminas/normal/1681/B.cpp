#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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
2
1 2
3
1 1 1
4
3 1 4 2
2
3 1
5
2 1 5 4 3
5
3 2 1 2 1
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 1; TESTT <= TESTS; ++TESTT) {
		int n, m;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		cin >> m;
		long long t = 0;

		for (int i = 0; i < m; ++i) {
			long long x;
			cin >> x;
			t += x;
		}

		cout << a[t % n] << "\n";
	}
}