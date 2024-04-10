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
abacaba
acaba
abacaba
acab
*/
/*input
6
first
first
second
second
third
third

*/
int sgn(long long t) {
	return t > 0 ? 1 : -1;
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;
	map<string, int> a;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		string t;
		cin >> t;

		if (a[t] == 0) {
			cout << "OK" << "\n";
		}
		else {
			cout << t << a[t] << "\n";
		}

		a[t]++;
	}
}