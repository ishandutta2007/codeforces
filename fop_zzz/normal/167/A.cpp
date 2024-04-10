#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
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

int n;
double a,d,tans;
int main()
{
	n=read();a=read();d=read();
	tans=0;
	while(n--)
	{
		double t=read(),v=read();
		double ans=0;
		bool flag=0;
		double ck=0.5*a*(v/a)*(v/a);
		if(ck>=d)
		{
			ans=sqrt(2*d/a);
			tans=max(tans,ans+t);
			printf("%.10lf\n",tans);
			flag=1;
		}
		ans=v/a;
		ans+=(d-ck)/v;
		if(!flag)	tans=max(tans,ans+t);
		if(!flag)printf("%.10lf\n",tans);
	}
}