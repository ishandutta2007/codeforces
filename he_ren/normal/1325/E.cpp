#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fir first
#define sec second
#define Mp make_pair
const int MAXN = 1e5 + 5;
const int MAXA = 1e6 + 5;
const int inf = 0x3f3f3f3f;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

int p[MAXA],pcnt,q[MAXA];
bool isnp[MAXA];
void sieve(void)
{
	isnp[0]=isnp[1]=1;
	for(int i=2; i<MAXA; ++i)
	{
		if(!isnp[i]) p[++pcnt]=i, q[i]=i;
		for(int j=1; j<=pcnt && (ll)p[j]*i<MAXA; ++j)
		{
			isnp[p[j]*i]=1;
			q[p[j]*i]=p[j];
			if(!(i%p[j])) break;
		}
	}
}

int a[MAXN];
pii b[MAXN];
map<pii,int> t;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXA],etot=0;
inline void addEdge(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int ans=inf;

void smlCir(int s)
{
	static int dis[MAXA];
	static int pre[MAXA];
	static queue<int> q;
	
	memset(dis,-1,sizeof(dis));
	dis[s]=0; pre[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(~dis[v])
			{
				if(v!=pre[u])
					chk_min(ans, dis[u]+dis[v]+1);
			}
			else
			{
				dis[v]=dis[u]+1; pre[v]=u;
				q.push(v);
			}
		}
	}
}

int main(void)
{
	sieve();
	p[0]=1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		int sa = sqrt(a[i]);
		if(sa*sa==a[i]) return printf("1"),0;
	}
	
	int sqa = 1e3;
	
	for(int i=1; i<=n; ++i)
	{
		int pp[5],now=0;
		int tmp = a[i];
		while(tmp>1)
		{
			int qq = q[tmp];
			bool flag=0;
			while(!(tmp%qq))
				tmp/=qq, flag^=1;
			if(flag) pp[++now]=qq;
		}
		
		if(now==1) b[i] = Mp(1,pp[1]);
		else
		{
			if(pp[1]>pp[2]) swap(pp[1],pp[2]);
			b[i] = Mp(pp[1],pp[2]);
		}
		
		if(t[b[i]]) return printf("2"),0;
		t[b[i]]=1;
		
		addEdge(b[i].fir, b[i].sec);
		addEdge(b[i].sec, b[i].fir);
	}
	
	for(int i=1; p[i]<=sqa; ++i)
		smlCir(p[i]);
	
	if(ans==inf) printf("-1");
	else printf("%d",ans);
	return 0;
}