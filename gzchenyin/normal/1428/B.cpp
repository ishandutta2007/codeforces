#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int dfn[300005],low[300005],color[300005],sta[300005],siz[300005],top,points,colors;
bool vis[300005];
vector<int> vec[300005];
void tarjan(int x)
{
	dfn[x]=low[x]=++points;
	vis[x]=true;
	sta[++top]=x;
	for(int i=0;i<vec[x].size();i++)
	{
		int y=vec[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		} 
		else if(vis[y])
		{
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x])
	{
		colors++;
		int cur=-1;
		while(cur!=x)
		{
			cur=sta[top];
			color[cur]=colors;
			siz[colors]++;
			vis[cur]=false;
			top--;
		}
	}
}
int n,t;
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<=n;i++) 
		{
			vis[i]=dfn[i]=low[i]=color[i]=siz[i]=0;
			vec[i].clear();
		}
		top=points=colors=0;
		for(int i=0;i<n;i++)
		{
			char tmp;
			scanf(" %c",&tmp);
			if(tmp=='-' || tmp=='>') vec[i].push_back((i+1)%n);
			if(tmp=='-' || tmp=='<') vec[(i+1)%n].push_back(i);
		}
		for(int i=0;i<n;i++) if(!dfn[i]) tarjan(i);
		int ans=0;
		for(int i=1;i<=colors;i++)
		{
			if(siz[i]==1) ans++;
		}
		printf("%d\n",n-ans);
	}
}