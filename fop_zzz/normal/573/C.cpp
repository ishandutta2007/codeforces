#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<cstdio>
#include<cctype>
#include<iostream>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define pa pair<int,int>
#define fir first
#define sec second
#define mk make_pair
#define eps 1e-8
#define inf 1e17

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

const int N=1e5+5;
int cnt[N][4],in[N],rt,head[N],nxt[N*2],poi[N*2],tcnt,n,flag=0;
inline void add(int x,int y)
{
	poi[++tcnt]=y;nxt[tcnt]=head[x];head[x]=tcnt;
	poi[++tcnt]=x;nxt[tcnt]=head[y];head[y]=tcnt;
	in[x]++;in[y]++;
} 
inline int Dfs(int x,int fa)
{
	cnt[x][0]=cnt[x][1]=cnt[x][2]=cnt[x][3]=0;
	int t=0;
	for(int i=head[x];i;i=nxt[i])
	if(poi[i]!=fa)
	{
		cnt[x][t=Dfs(poi[i],x)]++;//cout<<poi[i]<<' '<<t<<' '<<x<<endl;
		if(!flag)	if(t==0){flag=1,rt=poi[i];return 3;}
	}
	Dow(i,0,2)	cnt[x][i]+=cnt[x][i+1];
	if((flag&&cnt[x][0]-cnt[x][1])||cnt[x][1]-cnt[x][2]>2)
	{
		puts("No");exit(0);
	}
	if(cnt[x][0]==cnt[x][3]&&cnt[x][3]<=2)
	{
		if(cnt[x][0]<=1)	return 3;
		else	return 2;
	}  
	if(cnt[x][1]-cnt[x][2]<=1)	return 1;else	if(cnt[x][1]-cnt[x][2]==2)	return 0;
}
int main()
{
	n=read();
	For(i,1,n-1)	add(read(),read());
	For(i,1,n-1)	if(in[i]>in[rt])	rt=i;
	if(in[rt]<=2)
	{
		puts("Yes");
		return 0;
	}
	Dfs(rt,rt);	
	if(flag)	Dfs(rt,rt);
	puts("Yes");
}