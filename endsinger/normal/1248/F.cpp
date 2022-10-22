#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
vector<int>e[N],ans1,ans2;
int dfn[N],low[N],vis[N],stk[N],co[N],out[N],top,tim,cnt,n,m;
void tarjan(int u)
{
	dfn[u]=++tim;
	low[u]=tim;
	vis[u]=1;
	stk[++top]=u;
	for(auto v:e[u])
	{
		if(!dfn[v])
		{
			tarjan(v);
			low[u]=min(low[u],low[v]);	
		} 
		else if(vis[v])
			low[u]=min(low[u],low[v]);
	}
	if(dfn[u]==low[u])
	{
		cnt++;
		co[u]=cnt;
		vis[u]=0;
		while(stk[top]!=u)
		{
			co[stk[top]]=cnt;
			vis[stk[top--]]=0;
		}
		top--;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		tim=cnt=top=0,ans1.clear(),ans2.clear();
		for(int i=1;i<=n;i++)
		{
			dfn[i]=low[i]=vis[i]=stk[i]=co[i]=out[i]=0;
			e[i].clear();	
		}	
		for(int i=1;i<=m;i++)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(u!=v)
				e[u].push_back(v);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		if(cnt==1)
		{
			puts("No");
			continue;
		}
		for(int i=1;i<=n;i++)
			for(auto j:e[i])
				if(co[i]!=co[j])
					out[co[i]]++;
		int ju=0;
		for(int i=1;i<=cnt;i++)
			if(!out[i])
				ju=i;
		for(int i=1;i<=n;i++)
		{
			if(co[i]==ju)
				ans1.push_back(i);
			else
				ans2.push_back(i);	
		}		
		printf("Yes\n%d %d\n",ans1.size(),ans2.size());
		for(auto i:ans1)
			printf("%d ",i);
		puts("");
		for(auto i:ans2)
			printf("%d ",i);
		puts("");
	}	
	return 0;
}