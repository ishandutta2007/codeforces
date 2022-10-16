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
5 4
5 3 4 2 1
2 3 1
2 1 2
1 1 3
2 1 2
*/
/*input
5 9
2 3 5 1 4
2 3 5
2 5 5
2 5 1
2 5 3
2 5 4
1 5 4
2 5 3
2 2 5
2 5 1
*/

int sqrtn = 320;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;
	int p[n];
	int pr[n];
	int psq[n];

	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		p[i]--;
		pr[p[i]] = i;
	}

	for (int i = 0; i < n; ++i) {
		int t = i;

		for (int i = 0; i < sqrtn; ++i) {
			t = p[t];
		}

		psq[i] = t;
	}

	for (int i = 0; i < q; ++i) {
		int t, x, y;
		cin >> t >> x >> y;

		if (t == 1) {
			x--, y--;
			swap(p[x], p[y]);
			pr[p[x]] = x;
			pr[p[y]] = y;

			for (int ii : {
						x, y
					}) {
				int t = ii;

				for (int i = 0; i < sqrtn; ++i) {
					t = p[t];
				}

				for (int j = 0; j <= sqrtn; ++j) {
					psq[ii] = t;
					ii = pr[ii];
					t = pr[t];
				}
			}
		}
		else {
			x--;

			while (y >= sqrtn) {
				x = psq[x];
				y -= sqrtn;
			}

			while (y > 0) {
				x = p[x];
				y--;
			}

			cout << x + 1 << endl;
		}
	}


}