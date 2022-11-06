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

int p[MAXN], minlast[MAXN+1];

int solve(int n)
{


	return 0;
}

int main(int argc, char ** argv)
{
	int n;

	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> p[i];

	for (int i = 0; i <= n; i++)
		minlast[i] = INF;

	minlast[0] = -INF;

	for (int i = 0; i < n; i++) {
		int x = lower_bound(minlast, minlast+n+1, p[i])-minlast;
		minlast[x] = min(minlast[x], p[i]);
	}

	int result = 0;

	for (int i = n; i > 0; i--)
		if (minlast[i] < INF) {
			result = i;
			break;
		}

	cout << result << endl;
	
	return 0;
}