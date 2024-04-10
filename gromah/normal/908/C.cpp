#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1000 + 5

int n, r, X[N];
double Y[N];

double Calc(int x, int y)
{
	if (abs(X[x] - X[y]) > 2 * r) return r;
	double dy = sqrt(4 * r * r - (X[x] - X[y]) * (X[x] - X[y]));
	return dy + Y[y];
}

int main()
{
	scanf("%d%d", &n, &r);
	for (int i = 1; i <= n; i ++)
		scanf("%d", X + i);
	for (int i = 1; i <= n; i ++)
	{
		double Max = r;
		for (int j = 1; j < i; j ++)
			Max = max(Max, Calc(i, j));
		Y[i] = Max;
	}
	for (int i = 1; i <= n; i ++)
		printf("%.7f%c", Y[i], i == n ? '\n' : ' ');
	return 0;
}