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
5 2 2
8 3 1
2 1 3
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
		long long n, m, k;
		cin >> n >> m >> k;

		int t = 0;

		for (int i = 0; i < k; ++i) {
			set<int> did;
			int j = 0;

			for (; j < n % m; ++j) {
				cout << n / m + 1;

				for (int o = 0; o < n / m + 1; ++o) {
					cout << " " << 1 + t;
					did.insert(t);
					t = (t + 1) % n;
				}

				cout << "\n";
			}

			int oo = 0;

			for (; j < m; ++j) {
				cout << n / m;

				for (int o = 0; o < n / m; ++o) {
					while (did.count(oo)) {
						oo++;
					}

					cout << " " << 1 + oo;
					oo++;
				}

				cout << "\n";
			}
		}

		cout << "\n";
	}
}