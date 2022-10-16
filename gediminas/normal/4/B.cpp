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
1 48
5 7
*/
/*input
2 5
0 1
3 5
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int d;
	long long s;
	cin >> d >> s;
	long long mi[d], ma[d];

	long long t = 0;
	long long tt = 0;

	for (int i = 0; i < d; ++i) {
		cin >> mi[i] >> ma[i];
		t += mi[i];
		tt += ma[i];
	}

	if (s < t or s > tt) {
		cout << "NO";
		exit(0);
	}

	cout << "YES\n";

	s -= t;

	for (int i = 0; i < d; ++i) {
		long long y = min(ma[i] - mi[i], s);
		cout << y + mi[i] << " ";
		s -= y;
	}
}