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

int main(int argc, char ** argv)
{
	int n;

	scanf("%d", &n);

	int a = 0, b = 0;
	double diff = 0;

	for (int i = 0; i < 2*n; i++) {
		double v;
		scanf("%lf", &v);

		if (fabs(v - round(v)) < 1e-8) {
			a ++;
		} else {
			b ++;
			diff -= (v - floor(v));
		}
	}

	double ret = 1e200;

	for (int np1 = 0; np1 <= n; np1++)
		if (np1 <= b && n-np1 <= a)
			ret = min(ret, fabs(diff + 1.0*np1));

	printf("%.3f\n", ret);

	return 0;
}