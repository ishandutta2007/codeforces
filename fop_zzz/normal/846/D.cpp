#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
#include<algorithm>
#define For(i,j,k) for(ll i=j;i<=k;++i)
#define Dow(i,j,k) for(ll i=k;i>=j;--i)
#define ll long long
#define inf 1e17
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10LL+c-48LL,c=getchar();
	return t*f;
}
int a[1001][1001],sum[1001][1001],n,m,k,q;
struct zlx{int x,y,t;}p[1000001];
inline bool cmp(zlx x,zlx y){return x.t<y.t;}
inline bool check(int x)
{
	For(i,1,n)	For(j,1,m)	a[i][j]=sum[i][j]=0;
	For(i,1,x)	a[p[i].x][p[i].y]=1;
	For(i,1,n)
		For(j,1,m)	sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
	For(i,1,n-k+1)
		For(j,1,m-k+1)
		{
			int x1=i,x2=i+k-1,y1=j,y2=j+k-1;
			if(sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]==k*k)	return 1;
		}
	return 0;
}
int main()
{
	n=read();m=read();k=read();
	q=read();
	For(i,1,q)	p[i].x=read(),p[i].y=read(),p[i].t=read();
	sort(p+1,p+q+1,cmp);
	int l=1,r=q,ans=1e9;
	while(l<=r)
	{
		int mid=l+r>>1;
		if(check(mid))	ans=mid,r=mid-1;else	l=mid+1;
	}
	if(ans==1e9)	puts("-1");	else	printf("%d\n",p[ans].t);
}