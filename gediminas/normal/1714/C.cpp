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
4
20
8
45
10

*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	for (int i = 0; i < t; ++i) {
		int n;
		cin >> n;
		string t;

		for (int i = 9; i >= 1; --i) {
			if (i <= n) {
				n -= i;
				t.push_back('0' + i);
			}
		}

		if (n) {
			t.push_back('0' + n);
		}

		reverse(t.begin(), t.end());
		cout << t << "\n";
	}

}