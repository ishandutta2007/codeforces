#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
int n,m,t,p[100005],h[100005],siz[100005],ha[100005];
vector<int> vec[100005];
bool flag;
void dfs(int x,int fa)
{
	int tmp=0;
	siz[x]=p[x];
	for(int i=0;i<vec[x].size();i++)
	{
		if(vec[x][i]==fa) continue;
		dfs(vec[x][i],x);
		siz[x]+=siz[vec[x][i]];
		tmp+=ha[vec[x][i]];
	}
	if((h[x]+siz[x])%2 || h[x]>siz[x]) flag=false;
	ha[x]=(siz[x]+h[x])/2;
	if(ha[x]<tmp) flag=false;
//	printf("x=%d h=%d siz=%d ha=%d tmp=%d\n",x,h[x],siz[x],ha[x],tmp);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%*d",&n);
		for(int i=1;i<=n;i++) vec[i].clear();
		for(int i=1;i<=n;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++) scanf("%d",&h[i]);
		for(int i=1;i<=n-1;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		flag=true;
		dfs(1,0);
		if(flag) printf("YES\n");
		else printf("NO\n");
	}
}