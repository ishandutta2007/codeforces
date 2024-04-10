#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e16
#define db long double
#define pb push_back
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(!isdigit(c))	{if(c=='-')	f=-1;c=getchar();}
    while(isdigit(c))	t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x<0)	{putchar('-');write(-x);return;}if(x>=10)	write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
ll n,a[200001],ans,dp[200001];
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	ll mx=0;
	For(i,1,n)
	{
		mx=max(mx,a[i]);
		dp[i]=mx;
	}
	Dow(i,1,n-1)	dp[i]=max(dp[i],dp[i+1]-1);
	For(i,1,n)	ans+=dp[i]-a[i];
	writeln(ans); 
}