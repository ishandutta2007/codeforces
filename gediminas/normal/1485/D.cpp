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
2 3
16 16 16
16 16 16
*/
/*input
2 3
16 16 16
16 16 16
*/
/*input
2 2
3 11
12 8
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			long long a;
			cin >> a;

			if ((i + j) % 2 == 0) {
				cout << "720720 ";
			}
			else {
				cout << 720720 - a *a *a *a << " ";
			}
		}

		cout << "\n";
	}

}