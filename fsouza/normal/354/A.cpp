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
#define MAXN 100010

typedef long long lint;

using namespace std;

lint w[MAXN], rightsum[MAXN+1], leftsum[MAXN+1];

int main(int argc, char ** argv)
{
	lint n, l, r, ql, qr;

	cin >> n >> l >> r >> ql >> qr;
	
	for (int i = 0; i < n; i++)
		cin >> w[i];

	leftsum[0] = 0;
	for (int i = 0; i < n; i++)
		leftsum[i+1] = leftsum[i] + w[i];

	rightsum[0] = 0;
	for (int i = 0; i < n; i++)
		rightsum[i+1] = rightsum[i] + w[n-1-i];

	lint result = 1000000000000000LL;

	for (lint manyl = 0; manyl <= n; manyl++) {
		lint manyr = n-manyl;

		lint res = 0;
		res += leftsum[manyl] * l;
		res += rightsum[manyr] * r;

		if (manyl >= manyr)
			res += max(0LL, manyl-manyr-1) * ql;
		else
			res += max(0LL, manyr-manyl-1) * qr;

		result = min(result, res);
	}

	cout << result << endl;

	return 0;
}