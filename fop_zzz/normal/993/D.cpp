#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
using namespace std;
#define gc getchar
inline ll read()
{
	ll t=0,f=1;char c=gc();
	while(!isdigit(c))  {if(c=='-') f=-1;c=gc();}
	while(isdigit(c))   t=t*10+c-'0',c=gc();
	return t*f;
}
inline void write(ll x){if(x<0) {putchar('-');write(-x);return;}if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

double dp[101][101],a[101],b[101];
struct node{double c,a;}	p[101];
int n;
inline bool cmp(node x,node y){return x.a!=y.a?x.a>y.a:x.c>y.c;}
inline bool check(double x)
{
	For(i,1,n)  p[i].c=-(a[i]-b[i]*x),p[i].a=a[i];
	sort(p+1,p+n+1,cmp);
	For(i,0,n)  For(j,0,n)  dp[i][j]=-1e13;
	int i=1;
//	dp[1][1]=p[1].c;
//	dp[0][0]=0;
	int r=1;double tmp=p[1].c;
	while(p[r+1].a==p[1].a)   ++r,tmp+=p[r].c;
	dp[r][r]=tmp;
	while(1)
	{
		if(i>n) break;
		int l=i,r=i;
		while(p[r+1].a==p[l].a&&r<n)   ++r;
//		cout<<l<<' '<<r<<endl;
		double delta=0;
		For(j,l,r)  delta+=p[j].c;
		For(j,0,min(l-1,r-l+1))    //
		{
			For(k,j,l-1)
				if(dp[l-1][k]>-1e13)
					dp[r][k-j+(r-l+1-j)]=max(dp[r][k-j+(r-l+1-j)],dp[l-1][k]+delta);
			delta-=p[r-j].c;
		}
		i=r+1;
		if(i>n) break;
	}
	double ans=-1e13;
	For(i,0,n)    ans=max(ans,dp[n][i]);
	if(ans>=0)  return 1;else   return 0;
}
int main()
{
	n=read();
	For(i,1,n)  a[i]=read();
	For(i,1,n)  b[i]=read();
	double l=0,r=1e8;
	For(i,1,50)
	{
		double mid=(l+r)/2;
//		cout<<mid<<' '<<check(mid)<<endl;
		if(check(mid))  r=mid;else  l=mid;
	}
//	cout<<check(8.8)<<endl;
	ll ans=(long long)(l*1000+0.9999999999);
	writeln(ans);
}