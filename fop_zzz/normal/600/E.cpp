#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define int ll 

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

const int N=100005;
int poi[N*2],nxt[N*2],head[N],cnt,son[N],col[N],siz[N],n,m,tong[N],mx,sum,ans[N];
bool vis[N];
inline void add(int x,int y){poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;}
inline void Dfs(int x,int fa)
{
	siz[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		Dfs(poi[i],x);
		siz[x]+=siz[poi[i]];
		if(siz[poi[i]]>siz[son[x]])	son[x]=poi[i];
	}
}
inline void Chg(int x,int fa,int k)
{
	tong[col[x]]+=k;
	if(k>0&&tong[col[x]]>=mx)	
	{
		if(tong[col[x]]>mx)	sum=0,mx=tong[col[x]];
		sum+=col[x];
	}
	for(int i=head[x];i;i=nxt[i])	if(poi[i]!=fa&&!vis[poi[i]])	Chg(poi[i],x,k); 
}
inline void dsu(int x,int fa,int imp)
{
	if(!x)	return;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa||poi[i]==son[x])	continue;
		dsu(poi[i],x,0);
	}
	dsu(son[x],x,1);	
	vis[son[x]]=1;
	Chg(x,fa,1);
//	cout<<x<<"=>";
//	For(i,1,3)	cout<<tong[i]<<' ';cout<<endl;
	ans[x]=sum;
	if(son[x])	vis[son[x]]=0;
	if(!imp)	Chg(x,fa,-1),mx=sum=0;
}
signed main()
{
	n=read();
	For(i,1,n)	col[i]=read();
	For(i,1,n-1)
	{
		int x=read(),y=read();
		add(x,y);add(y,x);
	}
	Dfs(1,1);
	dsu(1,1,1);
	For(i,1,n)	write_p(ans[i]);
}