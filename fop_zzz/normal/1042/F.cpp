#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define pa pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define eps 1e-8


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

const int N=2e6+20;
int poi[N],nxt[N],head[N],dp[N],mx[N],n,k,rt,cnt,in[N];
inline void add(int x,int y)
{
	poi[++cnt]=y;nxt[cnt]=head[x];head[x]=cnt;
	poi[++cnt]=x;nxt[cnt]=head[y];head[y]=cnt;
	in[x]++;in[y]++;
}
inline void Dfs(int x,int fa)
{
	if(in[x]==1)	dp[x]=1;
	vector<int> tmp;
	for(int i=head[x];i;i=nxt[i])	
	{
		if(poi[i]==fa)	continue;
		Dfs(poi[i],x);
		tmp.pb(mx[poi[i]]+1);
		dp[x]+=dp[poi[i]];
	}
	if(tmp.empty())	return;
	sort(tmp.begin(),tmp.end());
	int siz=(int)tmp.size();
	if(siz>1)
	{
		Dow(i,1,siz-1)
		if(tmp[i]+tmp[i-1]<=k)
		{
			dp[x]-=i; 
			mx[x]=tmp[i];
			break;
		}
		if(!mx[x])	mx[x]=tmp[0];
	}else	mx[x]=tmp[0];
}
int main()
{
	n=read();k=read();
	For(i,1,n-1)	add(read(),read());
	For(i,1,n)	if(in[i]!=1)	rt=i;
	Dfs(rt,rt);
	writeln(dp[rt]);
}