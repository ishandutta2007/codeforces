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

int n;
struct node{double x,y;}	a[100005];
inline bool check(double R)
{
	double l=-2e7,r=2e7;
	For(i,1,n)
	{
		double b=-2*a[i].x,c=a[i].x*a[i].x+a[i].y*a[i].y-2*R*a[i].y;
		if(b*b-4*c<0)	return 0;
		double tl=(-b-sqrt(b*b-4*c))/2,tr=(-b+sqrt(b*b-4*c))/2;
		l=max(l,tl);r=min(r,tr);
//		cout<<tl<<' '<<tr<<endl;
	}
	if(l<=r)	return 1;
	return 0;
}
int main()
{
	n=read();
	For(i,1,n)	a[i].x=read(),a[i].y=read();
	bool z=0,f=0;
	For(i,1,n)	if(a[i].y<0)	f=1;else	if(a[i].y>0)	z=1;
	if(z&&f)	return puts("-1"),0;
	if(f)	For(i,1,n)	a[i].y=-a[i].y;
	double l=0,r=2e17,ans=0;
	For(i,1,120)
	{
		double mid=(l+r)/2;
		if(check(mid))	ans=mid,r=mid;else	l=mid;
	}	
//	check(0);
	printf("%.10lf",ans);
}