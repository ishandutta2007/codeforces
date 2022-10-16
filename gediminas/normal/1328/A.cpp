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
5
10 4
13 9
100 13
123 456
92 46
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int ttt;
	cin >> ttt;

	while (ttt--) {
		long long a, b;
		cin >> a >> b;
		cout << (b - a % b) % b << "\n";
	}

}