#include<bits/stdc++.h>
using namespace std;

int main() {
	int LA, RA, TA;
	int LB, RB, TB;
	cin >> LA >> RA >> TA;
	cin >> LB >> RB >> TB;

	assert(RA - LA + 1 < TA);
	assert(RB - LB + 1 < TB);

	int g = __gcd(TA, TB);
	RA -= (LA / g) * g;
	LA -= (LA / g) * g;

	RB -= (LB / g) * g;
	LB -= (LB / g) * g;

	assert(0 <= LA && LA < g);
	assert(0 <= LB && LB < g);
	if (LA > LB) {
		swap(LA, LB);
		swap(RA, RB);
		swap(TA, TB);
	}
	assert(LA <= LB);
	int res = 0;
	res = max(res, min(RA, RB) - max(LA, LB) + 1);
	assert(LA <= LB);
	LA += g;
	RA += g;
	res = max(res, min(RA, RB) - max(LA, LB) + 1);
	cout << res << '\n';

	return 0;
}