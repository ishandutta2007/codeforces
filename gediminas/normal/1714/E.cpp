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
10
2
6 11
3
2 18 22
5
5 10 5 10 5
4
1 2 4 8
2
4 5
3
93 96 102
2
40 6
2
50 30
2
22 44
2
1 5
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	const int maxn = 100;
	int prec[maxn + 1] = {};

	for (int i = 1; i <= maxn; ++i) {
		int t = i;

		while (t % 10 != 0 and t <= 2 * maxn) {
			t += t % 10;
		}

		if (t % 10 != 0) {
			prec[i] = t;
		}
	}

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		int a[n];
		set<int> x;

		for (int i = 0; i < n; ++i) {
			cin >> a[i];

			if (x.size() < 2) {
				if (prec[a[i] % maxn]) {
					x.insert(prec[a[i] % maxn]);
				}
				else {
					int t = a[i];

					while (t % 10 != 0) {
						t += t % 10;
					}

					x.insert(t);
				}
			}
		}

		cout << (x.size() <= 1 ? "Yes\n" : "No\n");
	}

}