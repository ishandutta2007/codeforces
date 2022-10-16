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
4
EEE
EN
ENNEENE
NENN
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		string c;
		cin >> c;
		int a = 0;

		for (auto &&x : c) {
			if (x == 'N') {
				a++;
			}
		}

		cout << ( a == 1 ? "NO" : "YES") << "\n";
	}
}