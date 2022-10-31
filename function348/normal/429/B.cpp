#include<cstdio>
#include<iostream>
#define  rep(i,a,b) for (int i=a;i<=b;i++)
#define _rep(i,a,b) for (int i=a;i>=b;i--)
using namespace std;
const int N=1010;
int a[N][N],b[N][N],c[N][N],d[N][N],e[N][N];
 
int n,m;
int main()
{
	scanf("%d%d",&n,&m);
	 rep(i,1,n)  rep(j,1,m) scanf("%d",&a[i][j]);
	 rep(i,1,n)  rep(j,1,m) b[i][j]=max(b[i-1][j],b[i][j-1])+a[i][j];
	_rep(i,n,1)  rep(j,1,m) c[i][j]=max(c[i+1][j],c[i][j-1])+a[i][j];
	 rep(i,1,n) _rep(j,m,1) d[i][j]=max(d[i-1][j],d[i][j+1])+a[i][j];
	_rep(i,n,1) _rep(j,m,1) e[i][j]=max(e[i+1][j],e[i][j+1])+a[i][j];
	
	int ans=0;
	
	rep(i,2,n-1) rep(j,2,m-1) ans=max(ans,b[i-1][j]+e[i+1][j]+c[i][j-1]+d[i][j+1]);
	rep(i,2,n-1) rep(j,2,m-1) ans=max(ans,b[i][j-1]+e[i][j+1]+c[i+1][j]+d[i-1][j]);
	
	printf("%d\n",ans);
	return 0;
}