#include <bits/stdc++.h>

using namespace std;

int T,l,r;
int sum[21][200005];

int main()
{
	scanf("%d",&T);
	for (int i = 0;i <= 20;i++)
		for (int j = 1;j <= 200000;j++)
			sum[i][j] = sum[i][j - 1] + (j >> i & 1);
	while (T--)
	{
		scanf("%d%d",&l,&r);
		int MIN = r - l + 1;
		for (int i = 0;i <= 20;i++)
		{
			int cnt = sum[i][r] - sum[i][l - 1];
			MIN = min(MIN,r - l + 1 - cnt);
		}
		printf("%d\n",MIN);
	}
	return 0;
}