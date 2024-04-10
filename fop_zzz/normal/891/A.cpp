#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define inf 2e13
#define pa pair<int,int>
#define sec second
#define mk make_pair
#define fir first

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

const int N=2004;
int n,a[N],ans,cnt;
inline int gcd(int x,int y){return y==0?x:gcd(y,x%y);}
int main()
{
	n=read();ans=3*n;
	For(i,1,n)	a[i]=read(),cnt+=(a[i]==1);
	For(i,1,n)	
	{
		int now=a[i],ned=0;
		For(j,i+1,n)
		{
			if(now==1)	break;
			now=gcd(now,a[j]);ned++;
		}
		if(now==1)	ans=min(ans,ned);
	}
	if(cnt)	{writeln(n-cnt);return 0;}
	if(ans!=3*n)	writeln(ans+n-1);else	puts("-1");
	
}