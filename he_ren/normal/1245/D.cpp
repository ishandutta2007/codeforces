#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e3 + 5;

inline ll Abs(ll x){ return x<0? -x: x;}

struct Node
{
	int x,y;
}a[MAXN];
inline ll dist(const Node &p,const Node &q){ return Abs(p.x-q.x)+Abs(p.y-q.y);}

struct Edge
{
	int u,v;
	ll w;
}e[MAXN*MAXN];
int etot=0;
inline bool cmp(const Edge &p,const Edge &q){ return p.w<q.w;}

int fa[MAXN*MAXN];
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
void connect(int u,int v){ fa[find(u)]=find(v);}

int c[MAXN],d[MAXN];

int au[MAXN];
Edge ae[MAXN*MAXN];
int ucnt=0,ecnt=0;

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&d[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			e[++etot] = (Edge){i,j,dist(a[i],a[j])*(d[i]+d[j])};
	for(int i=1; i<=n; ++i) e[++etot] = (Edge){0,i,c[i]};
	
	sort(e+1,e+etot+1,cmp);
	for(int i=0; i<=n; ++i) fa[i]=i;
	
	ll ans=0;
	for(int i=1; i<=etot; ++i)
	{
		int u=e[i].u, v=e[i].v;
		ll w=e[i].w;
		if(find(u)!=find(v))
		{
			connect(u,v);
			ans += w;
			
			if(!u) au[++ucnt]=v;
			else ae[++ecnt] = (Edge){u,v,w};
		}
	}
	
	cout<<ans<<endl;
	printf("%d\n",ucnt);
	for(int i=1; i<=ucnt; ++i) printf("%d ",au[i]);
	printf("\n%d\n",ecnt);
	for(int i=1; i<=ecnt; ++i) printf("%d %d\n",ae[i].u,ae[i].v);
	return 0;
}