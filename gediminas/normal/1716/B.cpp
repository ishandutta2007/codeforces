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
2
2
3
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		long long n;
		cin >> n;
		int a[n];

		cout << n << "\n";

		for (int i = 0; i < n; ++i) {
			a[i] = i + 1;
			cout << a[i] << " ";
		}

		cout << "\n";

		for (int i = 1; i < n; ++i) {
			swap(a[i], a[i - 1]);

			for (int i = 0; i < n; ++i) {
				cout << a[i] << " ";
			}

			cout << "\n";

		}
	}
}