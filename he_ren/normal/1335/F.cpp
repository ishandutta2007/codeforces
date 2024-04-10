#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define Mp make_pair
const int MAXN = 1e6 + 5;

struct Edge
{
	int next,to;
}e[MAXN];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int N,M;
char s[MAXN];
int a[MAXN];
inline int id(int x,int y){ return (x-1)*M + y;}

int to[MAXN];

bool been[MAXN], vis[MAXN], inc[MAXN];
int cir[MAXN],tot=0;
void find_cir(int u)
{
	tot=0;
	while(!been[u])
	{
		been[u] = 1;
		u = to[u];
	}
	int v=to[u];
	cir[++tot]=u;
	while(v!=u)
	{
		cir[++tot]=v;
		v=to[v];
	}
	for(int i=1; i<=tot; ++i)
		inc[cir[i]]=1;
	reverse(cir+1,cir+tot+1);
}

int val[MAXN];
void bfs_val(int beg,int now0)
{
	static queue<pii> q;
	
	q.push(Mp(beg,now0));
	while(!q.empty())
	{
		int u=q.front().first, now=q.front().second;
		q.pop();
		
		val[now] |= a[u];
		++now;
		if(now > tot) now=1;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(!inc[v]) q.push(Mp(v,now));
		}
	}	
}

void bfs_vis(int beg)
{
	static queue<int> q;
	
	q.push(beg);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		vis[u]=1;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(!vis[v]) q.push(v);
		}
	}
}

void solve(void)
{
	scanf("%d%d",&N,&M);
	for(int i=1; i<=N; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=M; ++j)
			a[id(i,j)] = !(s[j]-'0');
	}
	
	int n = N*M;
	for(int i=1; i<=n; ++i) head[i]=0;
	etot=0;
	for(int i=1; i<=N; ++i)
	{
		scanf("%s",s+1);
		for(int j=1; j<=M; ++j)
		{
			int u, v=id(i,j);
			if(s[j]=='U') u = id(i-1,j);
			if(s[j]=='D') u = id(i+1,j);
			if(s[j]=='L') u = id(i,j-1);
			if(s[j]=='R') u = id(i,j+1);
			add(u,v);
			to[v] = u;
		}
	}
	
	int ans1=0, ans2=0;
	
	for(int i=1; i<=n; ++i) been[i] = vis[i] = inc[i] = 0;
	for(int i=1; i<=n; ++i)
	{
		if(vis[i]) continue;
		find_cir(i);
		for(int j=1; j<=tot; ++j) val[j] = 0;
		for(int j=1; j<=tot; ++j)
			bfs_val(cir[j], j);
		
		ans1 += tot;
		for(int j=1; j<=tot; ++j)
			if(val[j]) ++ans2;
		
		bfs_vis(cir[1]);
	}
	
	printf("%d %d\n",ans1,ans2);
	
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}