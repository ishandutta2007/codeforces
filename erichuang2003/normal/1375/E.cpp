#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1005;

int n;
int p[MAXN];

pair<int,int> a[MAXN];

vector<pair<int,int> > ans;

int main()
{
	scanf("%d",&n);
	for (int i = 1;i <= n;i++)
	{
		scanf("%d",&a[i].first);
		a[i].second = i;
	}
	sort(a + 1,a + n + 1);
	for (int i = 1;i <= n;i++)
		p[i] = a[i].second;
	for (int i = 1;i <= n;i++)
		for (int j = 1;j < n;j++)
			if (p[j] > p[j + 1])
			{
				ans.push_back(make_pair(p[j + 1],p[j]));
				swap(p[j],p[j + 1]);
			}
	printf("%d\n",(int)ans.size());
	for (int i = 0;i < ans.size();i++)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}