#include<bits/stdc++.h>
using namespace std;
const int N=711;
int g[N][N];
int f[N][N][2];
int n,a[N];
int main(){
#ifdef flukehn
	freopen("g.in","r",stdin);
#endif
	cin>>n;
	int i,j,k,x,y;
	for(i=1;i<=n;++i){
		cin>>a[i];	
	}
	for(i=0;i<=n+1;++i)
		f[i][i][0]=f[i][i][1]=1;
	for(i=0;i<=n+1;++i)
		for(j=0;j<=n+1;++j)
			g[i][j]=__gcd(a[i],a[j])!=1;
	for(i=1;i<=n;++i)
	{
		for(j=1;(x=i+j)<=n+1;++j)
		{
			for(k=j;k<x;++k)
				f[j][x][0]|=g[j-1][k] && f[j][k][1] && f[k+1][x][0];
			for(k=j;k<x;++k)
				f[j][x][1]|=g[x][k] && f[j][k][1] && f[k+1][x][0];
		}
	}
	if(f[1][n+1][0] || f[1][n+1][1])
		puts("Yes");
	else
		puts("No");
}