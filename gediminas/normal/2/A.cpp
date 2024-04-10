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
mike 3
andrew 5
mike 2
*/
/*input
3
andrew 3
andrew 2
mike 5
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;

	map<string, int> tot;
	string a[n];
	int b[n];
	map<string, int> kada;

	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
		tot[a[i]] += b[i];
	}

	int ma = 0;

	for (auto &&[x, y] : tot) {
		ma = max(ma, y);
	}

	for (auto &&[x, y] : tot) {
		if (y == ma) {
			kada[x] = -1;
		}
	}

	tot.clear();

	for (int i = 0; i < n; ++i) {
		tot[a[i]] += b[i];

		if (tot[a[i]] >= ma and kada.count(a[i]) and kada[a[i]] == -1) {
			kada[a[i]] = i + 1;
		}
	}

	string fst = "";
	kada[fst] = 100000000;

	for (auto &&[x, y] : kada) {
		if (y < kada[fst]) {
			fst = x;
		}
	}

	cout << fst;
}