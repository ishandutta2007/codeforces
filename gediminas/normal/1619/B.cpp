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
10
1
25
1000000000
999999999
500000000
*/

long long pp(long long a, long long p) {
	long long t = 1;

	while (p--) {
		t *= a;
	}

	return t;
}

long long powll(long long a, long long p) {
	long long t = pow(a, 1.l / p);

	while (pp(t + 1, p) <= a) {
		t++;
	}

	while (pp(t - 1, p) > a) {
		t--;
	}

	return t;
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		long long a;
		cin >> a;
		cout << (powll(a, 2) + powll(a, 3) - powll(a, 6)) << "\n";
	}

}