#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;

int n, L, T, a[1000100];

double calc(int rem)
{
	double res = 0;
	for (int i = 0, j = 0; i < n; i++)
	{
		while (1)
		{
			int jj = (j + 1) % n;
			if (jj == i || (a[jj] + L - a[i]) % L > rem) break;
			j = jj;
		}
		res += n - (j + n - i) % n - 1;
		if (j == i) j++;
	}
	return res;
}

int main()
{
	cin >> n >> L >> T;
	for (int i = 0; i < n; i++) scanf("%d", a + i);
	double ans = (T * 2 / L + 1.0) * n * (n - 1);
	ans -= calc(T * 2 % L);
	printf("%.9lf\n", ans / 4);
}