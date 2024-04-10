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
4
1
6
2
6 8
4
1 3 3 7
2
4 2
1
50
2
25 50
10
1 2 3 4 5 6 7 8 9 10
2
5 15
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
		int b[m];

		for (int i = 0; i < m; ++i) {
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + m);
		cout << (a[n - 1] >= b[m - 1] ? "Alice" : "Bob") << "\n";
		cout << (a[n - 1] > b[m - 1] ? "Alice" : "Bob") << "\n";


	}
}