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

int c,d,flag;
inline void solve(int x)
{
	cout<<"?"<<' '<<c+(1<<x)<<' '<<d<<endl;
	int p1=read();
	cout<<"?"<<' '<<c<<' '<<d+(1<<x)<<endl;	
	int p2=read();
	if(p1!=p2)
	{
		if(p1==1)	return;
		else	
		{
			c=c+(1<<x);
			d=d+(1<<x);
			return;
		}
	}
	else
	{
		if(!flag)	
		{
			cout<<"?"<<' '<<c<<' '<<d<<endl;
			int p3=read();
			if(p3==1)	
				c=c+(1<<x);else	d=d+(1<<x);
		}
		else	if(flag==1)	c=c+(1<<x);else	d=d+(1<<x);
		if(p1==1)	flag=1;else	if(p1==-1)	flag=2;
	}
}
int main()
{
	c=0;d=0;
	Dow(i,0,29)	solve(i);
	cout<<"!"<<' '<<c<<' '<<d<<endl;
}