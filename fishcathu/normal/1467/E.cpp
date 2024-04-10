#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
int head[N],nex[N<<1],to[N<<1];
int a[N],b[N],sum[N];
int dfn[N],low[N],now[N];
int n,cnt;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void add(int l,int r,int val)
{
	b[l]+=val;
	b[r+1]-=val;
}
void dfs(int x,int f)
{
	dfn[x]=++cnt;
	int k=a[x],y=now[k]++;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		int z=now[k];
		dfs(t,x);
		if(z==now[k])continue;
		add(1,n,1);
		add(dfn[t],low[t],-1);
	}
	low[x]=cnt;
	if(now[k]-y!=sum[k])
	{
		add(dfn[x],cnt,1);
	}
}
int main()
{
	n=read();
	for(int i=1;i<=n;++i)a[i]=b[i]=read();
	sort(b+1,b+1+n);
	int m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;++i)
	{
		a[i]=lower_bound(b+1,b+1+m,a[i])-b;
		++sum[a[i]];
	}
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	memset(b+1,0,n<<2);
	cnt=0;
	dfs(1,0);
	putchar('\n');
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		b[i]+=b[i-1];
		if(!b[i])++ans;
	}
	write(ans,'\n');
}