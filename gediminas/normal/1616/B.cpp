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
10
codeforces
9
cbacbacba
3
aaa
4
bbaa

*/
/*input
2
5
cbbba
4
cbaa
4
ccaa

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		string a;
		cin >> a;
		int k = 1;

		for (int i = 0; i < n; ++i) {
			if (a[i] > a[i + 1]) {
				k = i + 2;
			}
			else if (a[i] == a[i + 1] and i != 0) {
				k = i + 2;
			}
			else {
				break;
			}
		}

		string b = a.substr(0, k);
		cout << b;
		reverse(b.begin(), b.end());
		cout << b << "\n";
	}

}