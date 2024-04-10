#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3E5+10;
ll read()
{
    ll a=0;char b=1,c;
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
int cnt;
bitset<N>b,vis;
void add(int u,int v)
{
	nex[++cnt]=head[u];
	head[u]=cnt;
	to[cnt]=v;
}
void dfs(int x)
{
	b[x]=vis[x]=1;
	for(int i=head[x];i;i=nex[i])if(b[to[i]])b[x]=0;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(!vis[t])dfs(t);
	}
}
void solve()
{
	int n=read(),m=read();
	for(int i=1;i<=n;++i)b[i]=vis[i]=head[i]=0;
	cnt=0;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		add(u,v);
		add(v,u);
	}
	dfs(1);
	for(int i=1;i<=n;++i)if(!vis[i])
	{
		puts("NO");
		return;
	}
	puts("YES");
	int s=0;
	for(int i=1;i<=n;++i)s+=b[i];
	write(s,'\n');
	for(int i=1;i<=n;++i)if(b[i])write(i,' ');
	putchar('\n');
}
int main()
{
	for(int x=read();x--;)
	{
		solve();
	}
}