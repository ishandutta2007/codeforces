#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define int ll 
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=200005;
int n,m,poi[N],cnt,head[N],nxt[N],Fa[N],bad[N],exp1[N],p[N],a[N],per[N];
bool son[N];
inline void Add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}
inline void Dfs(int x,int fa)
{
	Fa[x]=fa;
	for(int i=head[x];i;i=nxt[i])
	{
		int t=poi[i];
		if(t==fa)	continue;
		Dfs(t,x);p[x]+=p[t];
		son[x]=0;
	}
}
bool flag;
inline void Dfs1(int x)
{
	bad[x]=per[x];//
	for(int i=head[x];i;i=nxt[i])
	{
		int t=poi[i];
		if(t==Fa[x])	continue;
		Dfs1(t);bad[x]+=exp1[t];
	}
	if(bad[x]<exp1[x]&&(!flag))	flag=1,puts("NO");	
}
signed main()
{
	int T=read();
	while(T--)
	{
		cnt=0;
		n=read();m=read();
		For(i,1,n)	head[i]=0;
		For(i,1,n)	p[i]=read();
		For(i,1,n)	per[i]=p[i];
		For(i,1,n)	a[i]=read();
		For(i,1,n-1)	Add(read(),read());
		Dfs(1,1);
		flag=0;
		For(i,1,n)	
			if(((a[i]-p[i])&1)&&(!flag))	puts("NO"),flag=1;
		if(flag)	continue;
		For(i,1,n)	exp1[i]=(p[i]-a[i])/2;//
		For(i,1,n)	if(exp1[i]<0&&(!flag))	puts("NO"),flag=1;
		Dfs1(1);
		if(!flag)	puts("YES");
	}
}