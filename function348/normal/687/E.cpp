#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct Edge {int y,ne;};
const int N=5010;
int n,m,num,top,sent,ans;
Edge e[N];int last[N];
int dist[N],dfn[N],low[N],id[N],stk[N],d[N],size[N];
queue<int> Q;
void dfs(int i)
{
	dfn[i]=low[i]=++num;
	stk[++top]=i;
	for (int j=last[i];j;j=e[j].ne)
	if (dfn[e[j].y]==0)
	{
		dfs(e[j].y);
		low[i]=min(low[i],low[e[j].y]);
	}
	else if (id[e[j].y]==0) low[i]=min(low[i],low[e[j].y]);
	if (dfn[i]==low[i])
	{
		sent++;
		while (stk[top+1]!=i) id[stk[top--]]=sent,size[sent]++;
	}
}
void work(int k)
{
	int res=n+1;
	for (int i=1;i<=n;i++)
	if (id[i]==k)
	{
		for (int j=1;j<=n;j++) dist[j]=-1;
		dist[i]=0;
		while (!Q.empty()) Q.pop();
		Q.push(i);
		while (!Q.empty())
		{
			int now=Q.front();Q.pop();
			for (int j=last[now];j;j=e[j].ne)
			if (dist[e[j].y]==-1)
			{
				dist[e[j].y]=dist[now]+1;
				Q.push(e[j].y);
			}
			else if (dist[e[j].y]==0) res=min(res,dist[now]+1);
		}
	}
	ans+=res*998+1;
}
int main()
{
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		e[i]=(Edge){y,last[x]};last[x]=i;
	}
	num=0;
	for (int i=1;i<=n;i++)
	if (dfn[i]==0) dfs(i);
	for (int i=1;i<=n;i++)
	for (int j=last[i];j;j=e[j].ne)
	if (id[i]!=id[e[j].y]) d[id[i]]++;
	ans=n;
	for (int i=1;i<=sent;i++)
	if (size[i]>1&&d[i]==0) work(i);
	printf("%d\n",ans);
	return 0;
}