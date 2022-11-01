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
ll n,m;
int main()
{
	n=read();m=read();
	if(__gcd(n,m)-1)	return puts("Impossible"),0;
	while(n*m)
	{
		if(n>m)
		{
			ll t=n/m;
			ll tmp=t*m;
			if(tmp==n)	t--;
			write(t);putchar('A');
			n-=tmp;
		}else
		{
			ll t=m/n;
			ll tmp=t*n;
			if(tmp==m)t--;
			write(t);putchar('B');
			m-=tmp;
		}
	}	
}