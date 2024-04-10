#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>

using namespace std;

const int MAXN = 105;

int n,m,ans;
int a[MAXN][MAXN];
int sum[MAXN];

pair<int,int> v[MAXN];

vector<int> ANS;

int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
		{
			scanf("%d",&a[i][j]);
			sum[j] += a[i][j];
		}
	ans = m;
	for (int i = 1;i <= m;i++)
		ANS.push_back(i);
	for (int i = 1;i < n;i++)
	{
		for (int j = 1;j <= m;j++)
			v[j] = make_pair(a[j][i] - a[j][n],j);
		sort(v + 1,v + m + 1);
		int cur = 0,dif = sum[n] - sum[i];
		vector<int> S;
		while (dif > 0)
		{
			dif += v[++cur].first;
			S.push_back(v[cur].second);
		}
		if (cur < ans)
		{
			ans = cur;
			ANS = S;
		}
	}
	printf("%d\n",ans);
	for (int i = 0;i < ANS.size();i++)
		printf("%d ",ANS[i]);
	printf("\n");
	return 0;
}