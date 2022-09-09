#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;

int n,lim[MAXN];

int fa[MAXN],sz[MAXN],val[MAXN];
inline void init(int n)
{
	for(int i=1; i<=n; ++i)
		fa[i]=i, sz[i]=1, val[i]=lim[i];
}
int find(int u){ return fa[u]==u? u: fa[u]=find(fa[u]);}
inline void connect(int u,int v)
{
	int fu=find(u), fv=find(v);
	sz[fv]+=sz[fu]; fa[fu]=fv;
}

ll f[MAXN],g[MAXN];
int a[MAXN];

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&lim[i]);
	
	init(n);
	f[1]=lim[1];
	for(int i=2; i<=n; ++i)
	{
		ll sum=0;
		int j=i;
		while(j>1 && val[find(j-1)]>lim[i])
		{
			int fj=find(j-1);
			sum += (ll)val[fj]*(j-fj);
			val[fj]=lim[i];
			j=fj;
			connect(i,j);
		}
		f[i] = f[i-1] - sum + (ll)lim[i] * (i-j+1);
	}
	
	init(n);
	g[n]=lim[n];
	for(int i=n-1; i>=1; --i)
	{
		ll sum=0;
		int j=i;
		while(j<n && val[find(j+1)]>lim[i])
		{
			int fj=find(j+1);
			sum += (ll)val[fj]*(fj-j);
			val[fj]=lim[i];
			j=fj;
			connect(i,j);
		}
		g[i] = g[i+1] - sum + (ll)lim[i] * (j-i+1);
	}
	
	int ans=-1;
	ll tans=0;
	for(int i=1; i<=n; ++i)
	{
		ll tmp = f[i]+g[i]-lim[i];
		if(tmp>tans)
			ans=i,
			tans=tmp;
	}
	
	a[ans]=lim[ans];
	for(int i=ans-1; i>=1; --i)
		a[i] = min(a[i+1],lim[i]);
	for(int i=ans+1; i<=n; ++i)
		a[i] = min(a[i-1],lim[i]);
	
	for(int i=1; i<=n; ++i) printf("%d ",a[i]);
	return 0;
}