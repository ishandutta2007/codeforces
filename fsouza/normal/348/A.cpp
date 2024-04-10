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
#define MAXN 100000

typedef long long lint;

using namespace std;

lint A[MAXN];

bool can(int n, lint nround)
{
	lint maxr = 0;

	for (int i = 0; i < n; i++) {
		if (A[i] > nround)
			return false;
		maxr += nround - A[i];
	}

	return nround <= maxr;
}

int main(int argc, char ** argv)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> A[i];

	lint l = 0, r = 2000000001LL;

	while (l < r) {
		lint m = (l+r)/2;

		if (can(n, m))
			r = m;
		else
			l = m+1;
	}

	lint ret = l;

	cout << ret << endl;

	return 0;
}