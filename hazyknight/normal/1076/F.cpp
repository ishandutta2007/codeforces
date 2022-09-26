#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <iomanip>

using namespace std;

typedef long long ll;

const int MAXN = 300005;
const ll INF = (1ll << 60) - 1;

int n,k;
int x[MAXN];
int y[MAXN];

ll f[MAXN][2];

int main()
{
	scanf("%d%d",&n,&k);
	for (int i = 1;i <= n;i++)
		scanf("%d",&x[i]);
	for (int i = 1;i <= n;i++)
		scanf("%d",&y[i]);
	for (int i = 1;i <= n;i++)
	{
		f[i][0] = INF;
		f[i][1] = INF;
		if (x[i] > y[i])
		{
			ll MIN = f[i - 1][0];
			if (f[i - 1][1] != INF)
				MIN = 0;
			if (MIN != INF && (x[i] + MIN + k - 1) / k - 1 == y[i])
				f[i][0] = (x[i] + MIN - 1) % k + 1;
			if (MIN != INF && (x[i] + MIN + k - 1) / k - 1 < y[i])
				f[i][0] = 1;
		}
		else
		{
			ll MIN = f[i - 1][1];
			if (f[i - 1][0] != INF)
				MIN = 0;
			if (MIN != INF && (MIN + y[i] - 1) / k < x[i])
				f[i][0] = 1;
		}
		if (y[i] > x[i])
		{
			ll MIN = f[i - 1][1];
			if (f[i - 1][0] != INF)
				MIN = 0;
			if (MIN != INF && (y[i] + MIN + k - 1) / k - 1 == x[i])
				f[i][1] = (y[i] + MIN - 1) % k + 1;
			if (MIN != INF && (y[i] + MIN + k - 1) / k - 1 < x[i])
				f[i][1] = 1;
		}
		else
		{
			ll MIN = f[i - 1][0];
			if (f[i - 1][1] != INF)
				MIN = 0;
			if (MIN != INF && (MIN + x[i] - 1) / k < y[i])
				f[i][1] = 1;
		}
		if (f[i][0] > k)
			f[i][0] = INF;
		if (f[i][1] > k)
			f[i][1] = INF;
	//	cout << "f[" << i << "]=(" << f[i][0] << ',' << f[i][1] << ')' << endl;
	}
	if (f[n][0] == INF && f[n][1] == INF)
		printf("NO");
	else
		printf("YES");
	return 0;
}