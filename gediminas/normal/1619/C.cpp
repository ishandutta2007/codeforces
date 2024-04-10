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
6
17236 1106911
1 5
108 112
12345 1023412
1 11
1 20
*/

string ff(long long a, long long s, string b = "") {
	if (s == 0 || a == s) {
		return s == a and b[0] != '0' ? b : "-1";
	}

	if (a == 0) {
		return ff(0, s / 10, string(1, '0' + s % 10) + b);
	}

	if (a % 10 <= s % 10) {
		string t = ff(a / 10, s / 10, string(1, '0' + (s % 10 - a % 10)) + b);

		if (t != "-1") {
			return t;
		}
	}

	if (a % 10 > s % 10) {
		return s / 10 % 10 == 1 ? ff(a / 10, s / 100, string(1, '0' + (10 - a % 10 + s % 10)) + b) : "-1";
	}

	return "-1";
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long a, s;
		cin >> a >> s;
		cout << ff(a, s) << "\n";
	}

}