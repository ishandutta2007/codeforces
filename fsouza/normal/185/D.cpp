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

lint modpow(lint x, lint k, lint m)
{
	lint ret = 1%m;
	for (lint xp2y = x; k; xp2y = xp2y*xp2y%m, k >>= 1)
		if (k&1)
			ret = ret*xp2y%m;
	return ret;
}

lint inv(lint a, lint p)
{
	return modpow(a, p-2, p);
}

lint solvegp_p2(lint first, lint lrat, lint lmany, lint k, lint p)
{
	lint ratiomp = modpow(k, modpow(2, lrat, p-1), p);
	if (ratiomp == 1) 
		return first * modpow(2, lmany, p) % p;
	return first*(modpow(k, modpow(2, lrat+lmany, p-1), p) - 1 + p)%p * inv((ratiomp-1+p)%p, p) % p;
}

int solve(lint k, lint l, lint r, lint p)
{
	if (p == 2)
		return (k+1)%2;

	lint result;

	if (k%p == 0)
		result = 1;
	else
		result = solvegp_p2(1, l, r-l+1, k, p);

	if (k%2 == 1)
		result = result * modpow((p+1)/2, r-l, p) % p;

	return result;
}

int main(int argc, char ** argv)
{
	int ntest;

	cin >> ntest;
	
	for (int t = 0; t < ntest; t++) {
		lint k, l, r, p;

		cin >> k >> l >> r >> p;
		
		cout << solve(k, l, r, p) << endl;
	}

	return 0;
}