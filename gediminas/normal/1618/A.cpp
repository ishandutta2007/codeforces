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
1 3 4 4 5 7 8
1 2 3 4 5 6 7
300000000 300000000 300000000 600000000 600000000 600000000 900000000
1 1 2 999999998 999999999 999999999 1000000000
1 2 2 3 3 4 5
*/


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		vector<int> a(7);

		for (auto &&x : a) {
			cin >> x;
		}

		cout << a[0] << " " << a[1] << " " << (a[0] + a[1] == a[2] ? a[3] : a[2]) << "\n";
	}
}