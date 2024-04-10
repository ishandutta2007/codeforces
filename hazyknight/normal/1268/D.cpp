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

const int MAXN = 2005;

int n,ans;
int a[MAXN];
int deg[MAXN];

char s[MAXN][MAXN];

int popcount(int v)
{
	return v ? popcount(v - (v & -v)) + 1 : 0;
}

void del(int u,int v)
{
	s[u][v] = '0';
	deg[u]--;
}

void add(int u,int v)
{
	s[u][v] = '1';
	deg[u]++;
}

void rev(int u)
{
	for (int i = 1;i <= n;i++)
		if (i != u)
		{
			if (s[u][i] == '1')
			{
				del(u,i);
				add(i,u);
			}
			else
			{
				del(i,u);
				add(u,i);
			}
		}
}

bool isscc()
{
	memcpy(a,deg,sizeof(a));
	sort(a + 1,a + n + 1);
	reverse(a + 1,a + n + 1);
	int sum = 0;
	for (int i = 1;i < n;i++)
	{
		sum += a[i];
		if (sum == i * (i - 1) / 2 + i * (n - i))
			return 0;
	}
	return 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%s",s[i] + 1);
		for (int j = 1;j <= n;j++)
			if (s[i][j] == '1')
				deg[i]++;
	}
	if (isscc())
	{
		puts("0 1");
		return 0;
	}
	if (n <= 6)
	{
		ans = 1e9;
		int cnt = 0;
		for (int i = 0;i < (1 << n);i++)
		{
			for (int j = 0;j < n;j++)
				if (i >> j & 1)
					rev(j + 1);
			bool res = isscc();
			for (int j = 0;j < n;j++)
				if (i >> j & 1)
					rev(j + 1);
			if (!res)
				continue;
			int st = popcount(i);
			if (ans > st)
			{
				ans = st;
				cnt = 1;
			}
			else if (ans == st)
				cnt++;
		}
		if (ans == 1e9)
			puts("-1");
		else
			printf("%d %d\n",ans,cnt * max(ans,1));
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		rev(i);
		if (isscc())
			ans++;
		rev(i);
	}
	printf("1 %d\n",ans);
	return 0;
}