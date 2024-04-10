#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=2E5+10;
ll read()
{
	ll a=0;
	char b=1,c;
	do if((c=getchar())==45)b=-1;while(c<48||c>57);
	do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
	return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar('-'),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int head[N],nex[N],to[N];
int cnt,a[N],dep[N],q[N];
int fa[N],mx[N],mn[N];
ll add[N],sub[N],f[N];
ll mad[N],msb[N];
bitset<N>b;
void addd(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void solve()
{
	int n=read();
	for(int i=2;i<=n;++i)addd(fa[i]=read(),i);
	for(int i=2;i<=n;++i)a[i]=read();
	q[n+1]=0;
	for(int i=1,s=1,j=1;i<=n;++i)
	{
		int x=q[i],d=dep[x];
		if(!b[d])
		{
			b[d]=1;
			mx[d]=mad[d]=0;
			mn[d]=1<<30;
			msb[d]=-1<<30;
		}
		add[x]=f[fa[x]]+a[x];
		sub[x]=f[fa[x]]-a[x];
		mx[d]=max(mx[d],a[x]);
		mn[d]=min(mn[d],a[x]);
		mad[d]=max(mad[d],add[x]);
		msb[d]=max(msb[d],sub[x]); 
		for(int k=head[x];k;k=nex[k])
		{
			int t=to[k];
			dep[t]=d+1;
			q[++s]=t;
		}
		if(d==dep[q[i+1]])continue;
		while(j<=i)
		{
			x=q[j];
			ll l=max(add[x]-mn[d],sub[x]+mx[d]);
			ll r=max(mad[d]-a[x],msb[d]+a[x]);
			f[x]=max(l,r);
			++j;
		}
	}
	write(*max_element(f+1,f+1+n),'\n');
	for(int i=1;i<=n;++i)head[i]=0;
	cnt=0;
	for(int i=1;b[i];++i)b[i]=0;
}
int main()
{
	q[1]=1;
	for(int x=read();x--;)
	{
		solve();
	}
}