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
5
4
3 1 4 3
5
1 1 1 1 1
1
1
6
6 5 4 3 2 1
7
1 2 1 7 1 2 1

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		int a[n];

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		set<int> t;

		for (int i = n - 1; i >= 0; --i) {
			if (!t.insert(a[i]).second) {
				break;
			}
		}

		cout << n - t.size() << "\n";
	}

}