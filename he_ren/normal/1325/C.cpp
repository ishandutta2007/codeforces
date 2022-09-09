#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0,deg[MAXN];
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
	++deg[v];
}

int ans[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	if(n==2){ printf("0"); return 0;}
	
	memset(ans,-1,sizeof(ans));
	
	int u;
	for(int i=1; i<=n; ++i)
		if(deg[i]==1){ u=i; break;}
	for(int i=head[u]; i; i=e[i].next)
		ans[(i+1)>>1]=0;
	
	for(int i=u+1; i<=n; ++i)
		if(deg[i]==1){ u=i; break;}
	for(int i=head[u]; i; i=e[i].next)
		ans[(i+1)>>1]=1;
	
	int cnt=0;
	for(int i=1; i<=n; ++i)
		if(deg[i]==1) ++cnt;
	
	int now;
	if(cnt>2)
	{
		for(int i=u+1; i<=n; ++i)
			if(deg[i]==1){ u=i; break;}
		for(int i=head[u]; i; i=e[i].next)
			ans[(i+1)>>1]=2;
		now=3;
	}
	else now=2;
	
	for(int i=1; i<n; ++i)
	{
		if(~ans[i]) printf("%d\n",ans[i]);
		else printf("%d\n",now++);
	}
	return 0;
}