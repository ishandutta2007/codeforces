#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
int n,m,x,y,mx,anp,to; 
vector<pair<int,int> > g[5555];
int dist(int x,int y)
{
	if (y>=x) return y-x;
	return y-x+n;
}
long long ans;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		g[x].push_back(make_pair(dist(x,y),y)); 
	}
	for (int i=1;i<=n;i++) sort(g[i].begin(),g[i].end());
	for (int i=1;i<=n;i++)
	{
		mx=max(mx,(int)g[i].size());
	}
	for (int i=1;i<=n;i++)
	{
		anp=0;ans=0;
		for (int j=1;j<=n;j++)
		{
			if (g[j].size()==mx)
			{
				to=g[j][0].second;
				anp=max(anp,dist(i,j)+dist(j,to));
			}
			else if (g[j].size()+1==mx)
			{
				if (!g[j].size()) continue;
				to=g[j][0].second;
				if (i==j || dist(j,i)>dist(j,to)) continue;
				anp=max(anp,dist(i,to));
			}
		}	
		ans=1ll*(mx-1)*n+anp;
		printf("%lld ",ans);
	}
	printf("\n");
	return Accepted;
}