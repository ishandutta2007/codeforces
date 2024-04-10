#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;

int n,tot,ans;
int a[MAXN];

pair<int,int> b[MAXN];

int solve(int l,int r)
{
	if (l > r)
		return 0;
	if (b[l - 1].second >= 2 && b[r + 1].second >= 2 && b[l - 1].first == b[r + 1].first)
	{
		for (int i = l;i < r;i++)
			if (b[i].first != b[l - 1].first && b[i + 1].first != b[l - 1].first)
				return r - l + 1;
		return r - l;
	}
	else
		return r - l + 1;
}

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i]);
		if (!tot || b[tot].first != a[i])
			b[++tot] = make_pair(a[i],1);
		else
			b[tot].second++;
	}
	int st = 1;
	for (int i = 1;i <= tot;i++)
		if (b[i].second >= 2)
		{
			ans += solve(st,i - 1);
			ans += 2;
			st = i + 1;
		}
	ans += solve(st,tot);
	printf("%d\n",ans);
	return 0;
}