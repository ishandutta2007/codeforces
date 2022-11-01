#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1E5+10;
const int inf=1<<30;
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
int head[N],nex[N<<1],to[N<<1],cnt;
int a[N][40],c[40],y;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs1(int x,int f)
{
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		dfs1(t,x);
		for(int j=0;j<y;++j)
		{
			a[x][(j+1)%y]^=a[t][j];
		}
	}
}
void dfs2(int x,int f)
{
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		memcpy(c,a[t],y<<2);
		for(int j=0;j<y;++j)
		{
			a[t][(j+2)%y]^=a[x][(j+1)%y]^c[j];
		}
		dfs2(t,x);
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=n;--i;)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	for(int i=1;i<=n;++i)a[i][0]=read();
	y=m<<1;
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;++i)
	{
		int res=0;
		for(int j=m;j<y;++j)
		{
			res^=a[i][j];
		}
		write(!!res,' ');
	}
}