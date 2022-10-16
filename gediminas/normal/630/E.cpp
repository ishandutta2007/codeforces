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
1 1 5 5
*/
/*input
1 0 5 6
*/
// angry reacts only

long long div2(long long x) {
	return (x - (x % 2 == 0 ? 0 : 1)) / 2;
}

long long cntx(long long x, long long t) {
	if (x % 2 == 0) {
		return div2(t) + 1;
	}
	else {
		return div2(t + 1);
	}
}

long long cnt(long long c, long long t) {
	return (cntx(0, t) + cntx(1, t)) * c + cntx(0, t);
}

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	cout << cnt((x2 - x1) / 2, y2 - y1);
}