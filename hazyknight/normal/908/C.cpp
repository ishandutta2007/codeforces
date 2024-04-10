#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <cmath>

using namespace std;

int n;

double r,x[1005],y[1005];

int main()
{
	cin >> n >> r;
	for (int i = 1;i <= n;i++)
	{
		cin >> x[i];
		y[i] = r;
		for (int j = 1;j < i;j++)
			if (fabs(x[i] - x[j]) <= r * 2)
				y[i] = max(y[i],y[j] + sqrt(r * r * 4 - (x[i] - x[j]) * (x[i] - x[j])));
	}
	for (int i = 1;i <= n;i++)
		printf("%.7lf ",y[i]);
	return 0;
}