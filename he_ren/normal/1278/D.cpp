#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<map>
using namespace std;
#define fir first
#define sec second
const int MAXN = 5e5 + 5;

struct Seg
{
	int l,r;
	inline friend operator < (const Seg &p,const Seg &q){ return p.l<q.l;}
}a[MAXN];

map<int,int> t;

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

bool vis[MAXN];
void dfs(int u,int fa)
{
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		if(vis[v]){ printf("NO"); exit(0);}
		dfs(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].l,&a[i].r);
	
	sort(a+1,a+n+1);
	int tot=0;
	for(int i=1; i<=n; ++i)
	{
		map<int,int>::iterator it=t.lower_bound(-a[i].r);
		for(; it!=t.end(); ++it)
		{
			int tr = -(*it).fir;
			if(tr<a[i].l) break;
			
			if(++tot >= n){ printf("NO"); return 0;}
			add(i,(*it).sec);
			add((*it).sec,i);
		}
		t[-a[i].r]=i;
	}
	if(tot!=n-1){ printf("NO"); return 0;}
	dfs(1,0);
	for(int i=1; i<=n; ++i)
		if(!vis[i]){ printf("NO"); return 0;}
	printf("YES");
	return 0;
}