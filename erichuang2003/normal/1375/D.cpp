#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300005;

int T,n,tot;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];
int pos[MAXN];

vector<int> ans;

void doit(int p)
{
	ans.push_back(p);
	for (int i = 0;i <= n;i++)
		if (!cnt[i])
		{
			cnt[a[p]]--;
			a[p] = i;
			cnt[i]++;
			return;
		}
}

int main()
{
	scanf("%d",&T);
	while (T--)
	{
		scanf("%d",&n);
		ans.clear();
		for (int i = 0;i <= n;i++)
			cnt[i] = 0;
		for (int i = 1;i <= n;i++)
		{
			scanf("%d",&a[i]);
			cnt[a[i]]++;
		}
		int missing = 0;
		for (int i = 0;i <= n;i++)
			if (!cnt[i])
			{
				missing = i;
				break;
			}
		while (1)
		{
			if (missing)
			{
				doit(missing);
				for (int i = 0;i <= n;i++)
					if (!cnt[i])
					{
						missing = i;
						break;
					}
				continue;
			}
			for (int i = 1;i <= n;i++)
				if (a[i] != i)
				{
					doit(i);
					break;
				}
			for (int i = 0;i <= n;i++)
				if (!cnt[i])
				{
					missing = i;
					break;
				}
			if (!missing)
				break;
		}
		printf("%d\n",(int)ans.size());
		for (int i = 0;i < ans.size();i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}