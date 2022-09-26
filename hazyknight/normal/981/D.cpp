#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <queue>
#include <set> 
#include <vector>
#include <ctime>

using namespace std;

int n,k;

long long cur;
long long a[55];
long long sum[55][55];

bool f[55][55];

bool ok()
{
	memset(f,0,sizeof(f));
	f[0][0] = true;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j <= k;j++)
		{
			for (int k = 0;k < i;k++)
				if (f[k][j - 1] && (sum[k + 1][i] & cur) == cur)
					f[i][j] = true;
		}
	return f[n][k];
}

int main()
{
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
		cin >> a[i];
	for (int i = 1;i <= n;i++)
		for (int j = i;j <= n;j++)
			for (int k = i;k <= j;k++)
				sum[i][j] += a[k];
	for (int i = 60;i >= 0;i--)
	{
		cur ^= (1ll << i);
		if (!ok())
			cur ^= (1ll << i);
	}
	cout << cur << endl;
	return 0;
}