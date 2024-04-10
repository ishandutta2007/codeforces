#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <fstream>

using namespace std;

const int MAXN = 1000005;
const int INF = (1 << 30) - 1;

int n,m,ans;
int cnt[MAXN];
int f[MAXN][5][3];

int main()
{
	scanf("%d%d",&n,&m);
	for (int v,i = 1;i <= n;i++)
	{
		scanf("%d",&v);
		cnt[v]++;
	}
	for (int i = 1;i <= m;i++)
		for (int j = 0;j < 5;j++)
			for (int k = 0;k < 3;k++)
				f[i][j][k] = -INF;
	f[1][0][0] = 0;
	for (int i = 1;i < m;i++)
		for (int j = 0;j < 5;j++)
			for (int k = 0;k < 3;k++)
				if (f[i][j][k] != -INF)
				{
					for (int l = 0;l <= min(2,min(cnt[i - 1] - j,min(cnt[i] - k,cnt[i + 1])));l++)
						f[i + 1][k + l][l] = max(f[i + 1][k + l][l],f[i][j][k] + l + (cnt[i - 1] - j - l) / 3);
				}
	for (int i = 0;i < 5;i++)
		for (int j = 0;j < 3;j++)
			ans = max(ans,f[m][i][j] + (cnt[m - 1] - i) / 3 + (cnt[m] - j) / 3);
	cout << ans << endl;
	return 0;
}