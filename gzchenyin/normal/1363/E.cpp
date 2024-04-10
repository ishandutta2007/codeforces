#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
int n,b[200005],c[200005];
long long ans,a[200005];
vector<int> vec[200005];
int dfs(int x,int fa,long long cost)
{
	cost=min(cost,a[x]);
	int now=b[x]-c[x];
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==fa) continue;
		int tmp=dfs(vec[x][i],x,cost);
		if(tmp==0) continue;
		if(now*tmp<0) ans+=min(abs(now),abs(tmp))*cost;
		now+=tmp;
	}
	return now;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%d%d",&a[i],&b[i],&c[i]);
	}
	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	if(dfs(1,0,1000000001)!=0) printf("-1\n");
	else printf("%lld\n",2ll*ans);
}