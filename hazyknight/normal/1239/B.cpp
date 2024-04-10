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

const int MAXN = 300005;

int n,ans,x = 1,y = 1;
int sum[MAXN];
int sum1[MAXN];
int sum2[MAXN];
int val[MAXN];

char s[MAXN];

void solve(int v,int lim)
{
	for (int i = 1;i <= n;i++)
	{
		sum1[i] = sum1[i - 1] + (sum[i] == lim);
		sum2[i] = sum2[i - 1] + (sum[i] + v == lim);
		val[i] = sum2[i] - sum1[i];
	}
	int lst = 1,MIN = 1e9,t = 0,ed = 0;
	bool flag = 0;
	for (int i = n;i >= 1;i--)
		if (sum[i] < lim)
		{
			ed = i;
			break;
		}
	for (int i = 1;i < n;i++)
	{
		if (sum[i] + v < lim)
			MIN = 1e9;
		else
		{
			if (val[i - 1] < MIN && !flag && ((v < 0 && s[i] == '(') || (v > 0 && s[i] == ')')))
			{
				MIN = val[i - 1];
				t = i;
			}
			if (i >= ed && ((v < 0 && s[i + 1] == ')') || (v > 0 && s[i + 1] == '(')))
			{
				int cur = val[i] - MIN + sum1[n];
				if (cur > ans)
				{
					ans = cur;
					x = t;
					y = i + 1;
				}
			}
		}
		if (sum[i] < lim)
			flag = 1;
	}
}

int main()
{
	scanf("%d%s",&n,s + 1);
	int MIN = n;
	for (int i = 1;i <= n;i++)
	{
		if (s[i] == '(')
			sum[i] = sum[i - 1] + 1;
		else
			sum[i] = sum[i - 1] - 1;
		MIN = min(MIN,sum[i]);
	}
	if (sum[n])
	{
		printf("0\n1 1\n");
		return 0;
	}
	for (int i = 1;i <= n;i++)
		ans += (MIN == sum[i]);
	solve(-2,MIN - 2);
	solve(-2,MIN - 1);
	solve(-2,MIN);
	solve(2,MIN);
	solve(2,MIN + 1);
	solve(2,MIN + 2);
	printf("%d\n%d %d\n",ans,x,y);
	return 0;
}