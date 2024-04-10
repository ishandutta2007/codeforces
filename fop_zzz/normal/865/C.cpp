#include<bits/stdc++.h>
#define For(i,j,k)	for(int i=j;i<=k;++i)
#define Dow(i,j,k)	for(int i=k;i>=j;--i)
#define ll long long
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

const int N=55;
double dp[N][N*105];
int n;
int a[N],b[N];
double p[N],r;
inline double Get(int x,int y,double tim)
{
	if(y>r)	return tim;
	if(x==n+1)	return 0;else	return dp[x][y];
}
inline bool check(double tim)
{
	Dow(i,1,n)
	{
		For(j,0,r)
		{
			dp[i][j]=tim;
			dp[i][j]=min(dp[i][j],(Get(i+1,j+a[i],tim)+a[i])*p[i]+(Get(i+1,j+b[i],tim)+b[i])*(1.0-p[i]));
		}
	}
	return dp[1][0]<tim;
}
int main()
{
	n=read();r=read();
	For(i,1,n)	a[i]=read(),b[i]=read(),p[i]=1.0*read()/100.0;
	double l=0,r=1e9;
	double ans=-1;
	For(tt,1,200)
	{
		double mid=(l+r)/2.0;
		if(check(mid))	ans=mid,r=mid;else	l=mid;
	}
	printf("%.20lf",(double)ans);
}