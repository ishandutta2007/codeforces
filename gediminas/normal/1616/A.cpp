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
4
1 1 2 2
3
1 2 3
2
0 0

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		map<int, int> a;

		for (int i = 0; i < n; ++i) {
			int x;
			cin >> x;
			a[abs(x)]++;
		}

		int ans = 0;

		for (auto &&[x, y] : a) {
			ans += min(y, x == 0 ? 1 : 2);
		}

		cout << ans << "\n";
	}

}