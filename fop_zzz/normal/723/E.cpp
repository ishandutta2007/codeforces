#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	dp=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)	{putchar('-');x=-x;}	if(x>=10)	write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

const int N=200005;
int n,m,x,y,head[N],poi[N*2],nxt[N*2],in[N],cnt;
bool alr[N];
map<int,int> vis[N];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Dfs(int x)
{
	alr[x]=1;
	for(int &i=head[x];i;i=nxt[i])
	{
		if(vis[x][poi[i]])	continue;
		vis[x][poi[i]]=vis[poi[i]][x]=1;
		if(x!=n+1&&poi[i]!=n+1)
			write_p(x),writeln(poi[i]);
		Dfs(poi[i]);
	}
}
int main()
{
	int T=read();
	while(T--)
	{
		memset(alr,0,sizeof alr);
		n=read();m=read();
		For(i,1,n+1)	head[i]=0,vis[i].clear(),in[i]=0;cnt=0;
		For(i,1,m)
		{
			x=read();y=read();
			add(x,y);add(y,x);in[x]++;in[y]++;
		}
		int ans=n;
		For(i,1,n)	if(in[i]&1)	add(i,n+1),add(n+1,i),ans--;
		writeln(ans);
		For(i,1,n)	if(!alr[i])	Dfs(i);
		
	}
}