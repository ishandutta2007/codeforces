#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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
/*------------------------------------------------------------------------------------------------------*/

const int N=3e5;
int n,tot,ans,mo=1e9+7,dfn[N],low[N],q[N],inq[N],tim;
int poi[N*2],nxt[N*2],head[N],cnt1,top;
inline ll  ksm(ll x,ll y){ll sum=1;for(;y;y/=2,x=x*x%mo)	if(y&1)	sum=sum*x%mo;	return sum;}
inline void add(int x,int y){poi[++cnt1]=y;nxt[cnt1]=head[x];head[x]=cnt1;poi[++cnt1]=x;nxt[cnt1]=head[y];head[y]=cnt1;}

inline void Tar(int x,int fa)
{
	dfn[x]=++tim;low[x]=tim;q[++top]=x;inq[x]=1;
	for(int i=head[x];i;i=nxt[i])
	{
		if(poi[i]==fa)	continue;
		if(!dfn[poi[i]])	Tar(poi[i],x),low[x]=min(low[x],low[poi[i]]);
		else	if(inq[poi[i]])	low[x]=min(low[x],low[poi[i]]);
	}
	if(low[x]==dfn[x])
	{
		int cnt=0;
		while(1)
		{
			cnt++;
			inq[q[top]]=0;
			if(q[top]==x)	break;
			top--;
		}
		top--;
		if(cnt==1)	return;
		tot-=cnt;
		ans=(ans*(ksm(2,cnt)-2))%mo;ans=(ans%mo+mo)%mo;
	}
}
int a[N];
signed main()
{
	n=read();
	tot=n;ans=1;
	For(i,1,n)	add(i,a[i]=read());
	For(i,1,n)	if(!dfn[i]&&a[a[i]]==i)
	{
		ans=ans*2%mo;tot--;tot--;dfn[i]=dfn[a[i]]=1;
	}
	For(i,1,n)	if(!dfn[i])	Tar(i,i);
	ans=ans*ksm(2,tot)%mo;
	writeln(ans);
}