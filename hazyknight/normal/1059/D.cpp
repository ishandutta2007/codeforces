#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <assert.h>
#include <math.h>
#include <iomanip>

using namespace std;

const int MAXN = 100005;
const long double eps = 1e-8;

int n;

long double x[MAXN];
long double y[MAXN];

bool pos,neg;

bool ok(long double r)
{
	long double L = -1e14,R = 1e14;
	for (int i = 1;i <= n;i++)
	{
		if (y[i] > 2 * r)
			return false;
		long double len = sqrt(y[i] * (2 * r - y[i]));
		L = max(L,x[i] - len);
		R = min(R,x[i] + len);
		if (L > R)
			return false;
	}
	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin >> n;
	for (int X,Y,i = 1;i <= n;i++)
	{
		cin >> X >> Y;
		if (Y > 0)
			pos = true;
		if (Y < 0)
			neg = true;
		x[i] = X;
		y[i] = Y;
	}
	if (pos && neg)
	{
		cout << -1 << endl;
		return 0;
	}
	if (neg)
	{
		for (int i = 1;i <= n;i++)
			y[i] = -y[i];
	}
	long double low = 0,high = 1e14;
	while ((high - low) / max((long double)1,low) > eps)
	{
		long double mid = low + (high - low) / 2.0;
		if (ok(mid))
			high = mid;
		else
			low = mid + eps;
	}
	cout << fixed << setprecision(10) << low << endl;
	return 0;
}