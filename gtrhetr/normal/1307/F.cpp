#include<bits/stdc++.h>
using namespace std;

vector<int> v[400010];

int fa[400010][20],dep[400010];
int from[400010],dis[400010],n,k,r,tt;
bool inq[400010];

inline int rd()
{
	int x=0;char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

inline void print1() { putchar('Y');putchar('E');putchar('S');putchar('\n'); }
inline void print2() { putchar('N');putchar('O');putchar('\n'); }

inline int find(int x) { return (x==from[x])?x:from[x]=find(from[x]); }

inline int lca(int x,int y)
{
	if (dep[x]<dep[y]) swap(x,y);
	int t=dep[x]-dep[y];
	for (int i=18;~i;i--) if ((t>>i)&1) x=fa[x][i];
	if (x==y) return x;
	for (int i=18;~i;i--) if (fa[x][i]!=fa[y][i]) x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}

inline int jump(int x,int y)
{
	for (int i=18;~i;i--) if ((y>>i)&1) x=fa[x][i];
	return x;
}

inline void pre_dfs(int x)
{
	for (int i=1;i<19;i++) fa[x][i]=fa[fa[x][i-1]][i-1];
	for (int t:v[x]) if (t!=fa[x][0])
	{
		dep[t]=dep[x]+1;
		fa[t][0]=x;pre_dfs(t);
	}
}

inline void pre_bfs()
{
	queue<int> q;
	for (int i=1;i<=tt;i++) from[i]=i;
	for (int i=1;i<=r;i++)
	{
		int x=rd();
		dis[x]=k/2;inq[x]=true;q.push(x);
	}
	while (!q.empty())
	{
		int x=q.front();q.pop();
		if (!dis[x]) return;
		for (int t:v[x])
		{
			from[find(t)]=find(x);
			if (!inq[t]) dis[t]=dis[x]-1,inq[t]=true,q.push(t);
		}
	}
}

int main()
{
	n=rd();k=rd()*2;r=rd();tt=n;
	for (int i=1;i<n;i++)
	{
		int x=rd(),y=rd();tt++;
		v[x].push_back(tt);v[tt].push_back(x);
		v[y].push_back(tt);v[tt].push_back(y);
	}
	dep[1]=1;pre_dfs(1);pre_bfs();
	int Q=rd();
	while (Q--)
	{
		int x=rd(),y=rd(),hh=lca(x,y),d=dep[x]+dep[y]-dep[hh]*2;
		if (d<=k) { print1();continue; }
		int h1=(dep[x]-dep[hh]>=k/2)?jump(x,k/2):jump(y,d-k/2);
		int h2=(dep[y]-dep[hh]>=k/2)?jump(y,k/2):jump(x,d-k/2);
		if (find(h1)==find(h2)) print1();
		else print2();
	}
	return 0;
}