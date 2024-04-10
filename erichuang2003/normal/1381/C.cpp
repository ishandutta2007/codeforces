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

int T,n,x,y,tot;
int a[MAXN];
int d[MAXN];
int ans[MAXN];

vector<int> pos[MAXN];
vector<int> cnt[MAXN];

bool cmp(const int &u,const int &v)
{
	return a[u] < a[v];
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for (int i = 1;i <= n + 1;i++)
			pos[i].clear();
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			ans[i] = 0;
			pos[a[i]].push_back(i);
		}
		int missing = 0;
		for (int i = 1;i <= n + 1;i++)
			if (!pos[i].size())
			{
				missing = i;
				break;
			}
		for (int i = 0;i <= n;i++)
			cnt[i].clear();
		for (int i = 1;i <= n + 1;i++)
			cnt[pos[i].size()].push_back(i);
		int cur = n;
		while (x--)
		{
			while (cur && !cnt[cur].size())
				cur--;
			int u = cnt[cur].back();
			cnt[cur].pop_back();
			cnt[cur - 1].push_back(u);
			ans[pos[u].back()] = u;
			pos[u].pop_back();
		}
		while (cur && !cnt[cur].size())
			cur--;
		y = n - y;
		tot = 0;
		for (int i = 1;i <= n;i++)
			if (!ans[i])
				d[++tot] = i;
		sort(d + 1,d + tot + 1,cmp);
		bool ok = 1;
		for (int i = 1;i <= tot;i++)
		{
			if (a[d[i]] == a[d[(i + (tot / 2) - 1) % tot + 1]])
			{
				if (!y)
				{
					ok = 0;
					break;
				}
				else
				{
					y--;
					ans[d[i]] = missing;
				}
			}
			else
				ans[d[i]] = a[d[(i + (tot / 2) - 1) % tot + 1]];
		}
		cur = 1;
		while (y--)
		{
			while (ans[d[cur]] == missing)
				cur++;
			ans[d[cur]] = missing;
		}
		if (!ok)
		{
			puts("NO");
			continue;
		}
		puts("YES");
		for (int i = 1;i <= n;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}