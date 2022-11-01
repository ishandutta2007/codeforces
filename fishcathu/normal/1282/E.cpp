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
int a[N][3],n,m,nbr[N][2];
pii c[N*3];
int head[N],nex[N*3],to[N*3],cnt;
int b[N],q[N];
bitset<N>vis;
void add1(int u,int v)
{
	nbr[u][!!nbr[u][0]]=v;
}
void add2(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void solve1()
{
	cnt=0;
	for(int i=1;i<=m;++i)
	{
		for(int j=0;j<3;++j)
		{
			for(int k=j+1;k<3;++k)
			{
				int l=a[i][j],r=a[i][k];
				if(l>r)swap(l,r);
				c[++cnt]={l,r};
			}
		}
	}
	sort(c+1,c+1+cnt);
	for(int i=1;i<=n;++i)nbr[i][0]=0;
	c[cnt+1]={0,0};
	for(int i=1;i<=cnt;++i)
	{
		if(c[i]==c[i+1])++i;
		else
		{
			add1(c[i].fi,c[i].se);
			add1(c[i].se,c[i].fi);
		}
	}
	for(int x=1,f=0;1;)
	{
		write(x,' ');
		int t=nbr[x][nbr[x][0]==f];
		if(t==1)break;
		f=x;
		x=t;
	}
	putchar('\n');
}
void solve2()
{
	cnt=0;
	memset(head+1,0,n<<2);
	for(int i=1;i<=m;++i)
	{
		vis[i]=0;
		for(int j=0;j<3;++j)
		{
			add2(a[i][j],i);
			++b[a[i][j]];
		}
	}
	cnt=0;
	for(int i=1;i<=n;++i)
	{
		if(b[i]==1)
		{
			q[++cnt]=i;
		}
	}
	for(int i=1;i<=m;++i)
	{
		int w;
		for(int j=head[q[i]];j;j=nex[j])
		{
			int t=to[j];
			if(vis[t])continue;
			w=t;
			break;
		}
		write(w,' ');
		vis[w]=1;
		for(int j=0;j<3;++j)
		{
			if(--b[a[w][j]]==1)
			{
				q[++cnt]=a[w][j];
			}
		}
	}
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		n=read();
		m=n-2;
		for(int i=1;i<=m;++i)
		{
			for(int j=0;j<3;++j)
			{
				a[i][j]=read();
			}
		}
		solve1();
		solve2();
	}
}