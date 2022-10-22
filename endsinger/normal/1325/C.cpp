#include<bits/stdc++.h>
using namespace std;
const int N=100005;
vector<pair<int,int>>e[N];
int n,ans[N],d[N],cnt;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].emplace_back(v,i);
		e[v].emplace_back(u,i);
		d[u]++;
		d[v]++;
	}
	memset(ans,-1,sizeof(ans));
	for(int i=1;i<=n;i++)
	{
		if(d[i]>=3)
		{
			for(int j=0;j<3;j++)
				ans[e[i][j].second]=j;
			cnt=2;
			for(int i=1;i<n;i++)
			{
				if(ans[i]!=-1)
					printf("%d\n",ans[i]);
				else
				{
					cnt++;
					printf("%d\n",cnt);
				}
			}
			return 0;
		}
	}
	for(int i=0;i<n-1;i++)
		printf("%d\n",i);
	return 0;
}