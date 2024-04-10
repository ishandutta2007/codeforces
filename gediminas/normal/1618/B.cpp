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
4
7
ab bb ba aa ba
7
ab ba aa ab ba
3
aa
5
bb ab bb

*/


int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		bool rad = false;
		string a;
		cin >> a;
		cout << a;

		for (int i = 3; i < n; ++i) {
			string b;
			cin >> b;

			if (a[1] != b[0]) {
				cout << b[0];
				rad = true;
			}

			cout << b[1];
			a = b;
		}

		if (!rad) {
			cout << a[1];
		}
		cout << "\n";
	}
}