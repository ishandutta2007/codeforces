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
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

const int MAXN = 100005;

int T,n;
int fa[25];
int cnt[25];

char a[MAXN];
char b[MAXN];

int getroot(int u)
{
	return u == fa[u] ? u : fa[u] = getroot(fa[u]);
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%s%s",&n,a + 1,b + 1);
		bool ok = 1;
		for (int i = 1;i <= n;i++)
			if (a[i] > b[i])
				ok = 0;
		if (!ok)
		{
			puts("-1");
			continue;
		}
		for (int i = 1;i <= 20;i++)
			fa[i] = i,cnt[i] = 0;
		for (int i = 1;i <= n;i++)
			fa[getroot(a[i] - 'a' + 1)] = getroot(b[i] - 'a' + 1);
		for (int i = 1;i <= 20;i++)
			cnt[getroot(i)]++;
		int ans = 0;
		for (int i = 1;i <= 20;i++)
			ans += max(0,cnt[i] - 1);
		printf("%d\n",ans);
	}
	return 0;
}