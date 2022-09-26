#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>

using namespace std;

int f(int p)
{
	int ret = 1;
	while (p > 0)
	{
		if (p % 10 != 0)
			ret *= p % 10;
		p /= 10;
	}
	return ret;
}

int g[1000005],q;
int cnt[10][1000005];

int main()
{
	for (int i = 1;i <= 1000000;i++)
	{
		if (i < 10)
			g[i] = i;
		else
			g[i] = g[f(i)];
	}
	for (int i = 1;i <= 9;i++)
		for (int j = 1;j <= 1000000;j++)
			cnt[i][j] = cnt[i][j - 1] + (g[j] == i);
	cin >> q;
	for (int i = 1;i <= q;i++)
	{
		int l,r,k;
		cin >> l >> r >> k;
		cout << cnt[k][r] - cnt[k][l - 1] << endl; 
	}
	return 0;
}