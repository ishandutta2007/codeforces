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
const int N=1E5+10;
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
int size[N],n,mn,l,r;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int x,int f)
{
	int mx=0;
	size[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==f)continue;
		dfs(t,x);
		mx=max(mx,size[t]);
		size[x]+=size[t];
	}
	mx=max(mx,n-size[x]);
	if(mx<mn)mn=mx,l=x,r=0;
	else if(mx==mn)r=x;
}
void solve()
{
	n=read();
	for(int i=1;i<=n;++i)head[i]=0;
	cnt=0;
	mn=1<<30;
	for(int i=n;--i;)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	if(!r)r=l;
	int t=head[l];
	while(to[t]==r)t=nex[t];
	t=to[t];
	write(l,' ');
	write(t,'\n');
	write(r,' ');
	write(t,'\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}