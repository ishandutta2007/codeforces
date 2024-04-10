#pragma comment(linker, "/stack:200000000")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back


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
/*------------------------------------------------------------------------------------------------------*/
const int N=1005;
bool vis[N];
int d1[N],f1[N],d2[N],f2[N],q[N],top,cnt,poi[N*2],nxt[N*2],head[N],tot,Fa[N],n,m;
struct node{int dis,rt;}	tr[N];
inline bool cmp(node x,node y){return x.dis>y.dis;}
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
}
inline void Dfs(int x)
{
	d1[x]=0;f1[x]=x;vis[x]=1;q[++top]=x;
	for(int i=head[x];i;i=nxt[i])
	{
		if(vis[poi[i]])	continue;
		Fa[poi[i]]=x;
		Dfs(poi[i]);
		if(d1[poi[i]]+1>d1[x])	d2[x]=d1[x],f2[x]=f1[x],d1[x]=d1[poi[i]]+1,f1[x]=f1[poi[i]];
		else	if(d1[poi[i]]+1>d2[x])	d2[x]=d1[poi[i]]+1,f2[x]=f1[poi[i]];
	}
}
int ans;
inline void Solve(int x)
{
	++tot;
	top=0;
	Dfs(x);
	int dis=0,sta=0;
	For(i,1,top)	if(d1[q[i]]+d2[q[i]]>=dis)	dis=max(dis,d1[q[i]]+d2[q[i]]),sta=f1[q[i]];
	tr[tot].dis=(dis+1)/2;ans=max(ans,dis);
	while(1)
	{
//		cout<<sta<<' '<<dis<<'-'<<d1[sta]<<endl;
		if(abs(d1[sta]-(dis-d1[sta]))<=1)	{tr[tot].rt=sta;break;}
		sta=Fa[sta];
	}
	
}
int main()
{
	n=read();m=read();
	For(i,1,m)	add(read(),read());
	For(i,1,n)
		if(!vis[i])	Solve(i);
	sort(tr+1,tr+tot+1,cmp);
	if(tot>=2)ans=max(ans,tr[1].dis+tr[2].dis+1);
	if(tot>=3)	ans=max(ans,tr[2].dis+tr[3].dis+2);
	writeln(ans);
	For(i,2,tot)
	{
		write_p(tr[1].rt);
		writeln(tr[i].rt);
	}
}