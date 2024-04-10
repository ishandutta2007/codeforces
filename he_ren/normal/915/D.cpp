#include<cstdio>
const int MAXN = 5e2 + 5;
const int MAXM = 1e5 + 5;

struct Edge
{
	int next,to;
	bool del;
}e[MAXM];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v,0};
	head[u]=etot;
}

int cir[MAXN],ccnt=0;
bool vis[MAXN],ins[MAXN],fnd=0;
bool dfs(int u)
{
	vis[u]=ins[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		if(e[i].del) continue;
		
		int v=e[i].to;
		if(ins[v])
		{
			if(fnd) cir[++ccnt]=i;
			return v;
		}
		if(!vis[v])
		{
			int t=dfs(v);
			if(t>0 && fnd) cir[++ccnt]=i;
			if(t==u) return -1;
			if(t) return t;
		}
	}
	ins[u]=0;
	return 0;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	
	fnd=1;
	for(int i=1; i<=n && !ccnt; ++i)
		if(!vis[i]) dfs(i);
	fnd=0;
	
	if(!ccnt)
	{
		printf("YES");
		return 0;
	}
	for(int i=1; i<=ccnt; ++i)
	{
		e[cir[i]].del=1;
		for(int j=1; j<=n; ++j)
			ins[j]=vis[j]=0;
		
		bool flag=1;
		for(int j=1; j<=n; ++j)
			if(!vis[j] && dfs(j))
			{
				flag=0;
				break;
			}
		if(flag)
		{
			printf("YES");
			return 0;
		}
		e[cir[i]].del=0;
	}
	printf("NO");
	return 0;
}