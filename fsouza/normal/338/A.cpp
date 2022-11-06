#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/3)

typedef long long lint;

using namespace std;

const lint mod = 1000000009LL;

lint modpow(lint x, int y, lint mod)
{
	if (y == 0) return 1;
	lint k = modpow(x, y/2, mod);
	k = (k*k)%mod;
	if (y%2) return k*x%mod;
	return k;
}

int main(int argc, char ** argv)
{
	int n, m, k;

	scanf("%d %d %d", &n, &m, &k);
	
	int nok = m;
	int nwrong = n-m;

	int ncombo;
	int l = 0, r = nok+1;

	while (l != r) {
		ncombo = (l+r)/2;

		if ((lint)ncombo*(lint)k > (lint)nok) {
			r = ncombo-1;
			continue;
		}

		int rest = nok - ncombo*k;
		int needsep = max((rest + (k-2)) / (k-1) - 1, 0);

		if (nwrong >= needsep) {
			r = ncombo;
		} else {
			l = ncombo+1;
		}
	}
	ncombo = l;
	
	lint rest = nok - ncombo*k;

	lint mp = modpow(2, ncombo+1, mod);
	lint x = (mp - 2 + mod)%mod;
	lint xk = (((lint)k)*x)%mod;

	lint score = (xk + rest)%mod;

	printf("%d\n", (int)score);

	return 0;
}