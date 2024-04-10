#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>

map<int,int> id;

pii c[210];
int to1[210][210];

int S[210];
int num[210],to[210][210],h[210],h1[210],a[200010],n,k,tt,tot;
bool vis[210];
bool have[210][210];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void dfs(int x,int y)
{
	if (x>k)
	{
		num[++tt]=y;id[y]=tt;
		return;
	}
	for (int i=1;i<=k;i++) if (!vis[i])
	{
		vis[i]=true;
		dfs(x+1,y*(k+1)+i);
		vis[i]=false;
	}
}

inline void gao(int id,int y)
{
	queue<int> q;
	memset(vis,false,sizeof(vis));
	for (int i=1;i<=tt;i++) if (have[id][i]) q.push(i),vis[i]=true;
	q.push(y);
	vis[1]=true;
	while (!q.empty())
	{
		int x=q.front();q.pop();
		for (int i=1;i<=tt;i++) if (vis[i])
		{
			if (!vis[to[i][x]]) vis[to[i][x]]=true,q.push(to[i][x]);
			if (!vis[to[x][i]]) vis[to[x][i]]=true,q.push(to[x][i]);
		}
	}
}

inline void bfs()
{
	queue<int> q;
	tot=1;have[1][1]=1;q.push(1);
	while (!q.empty())
	{
		int hh=q.front();q.pop();
		for (int i=1;i<=tt;i++) if (!have[hh][i])
		{
			gao(hh,i);
			bool flag=false;int hhh=0;
			for (int j=1;j<=tot;j++)
			{
				bool bb=true;
				for (int k=1;k<=tt;k++) if (have[j][k]!=vis[k]) bb=false;
				if (bb) { flag=true;hhh=j;break; }
			}
			if (!flag)
			{
				hhh=++tot;
				for (int j=1;j<=tt;j++) have[tot][j]=vis[j];
				q.push(tot);
			}
			to1[hh][i]=hhh;
		}
	}
	for (int i=1;i<=tot;i++) for (int j=1;j<=tt;j++) if (have[i][j]) S[i]++;
}

int lst[210];

int main()
{
	n=rd();k=rd();tt=0;
	dfs(1,0);
	for (int i=1;i<=tt;i++) for (int j=1;j<=tt;j++)
	{
		int hh=num[i];
		for (int l=k;l;l--) h[l]=hh%(k+1),hh/=(k+1);
		hh=num[j];
		for (int l=k;l;l--) h1[l]=h[hh%(k+1)],hh/=(k+1);
		int now=0;
		for (int l=1;l<=k;l++) now=now*(k+1)+h1[l];
		to[i][j]=id[now];
	}
	bfs();
	for (int i=1;i<=n;i++)
	{
		int now=0;
		for (int j=1;j<=k;j++) now=now*(k+1)+rd();
		a[i]=id[now];
	}
	ll ans=0;
	for (int i=1;i<=n;i++)
	{
		lst[a[i]]=i;
		int cnt=0;
		for (int j=1;j<=tt;j++) if (lst[j]) c[++cnt]=pii(lst[j],j);
		sort(c+1,c+cnt+1);
		int now=1;
		for (int j=cnt;j;j--)
		{
			if (!have[now][c[j].second]) now=to1[now][c[j].second];
			ans+=S[now]*(c[j].first-c[j-1].first);
		}
	}
	printf("%lld\n",ans);
	return 0;
}