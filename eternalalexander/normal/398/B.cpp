#include <bits/stdc++.h>
int n,m,p[2005],q[2005];
double f[2005][2005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		p[x]=q[y]=1;
	}int r=0,c=0;
	for(int i=1;i<=n;++i)r+=p[i],c+=q[i];
	for(int i=n;i>=0;--i){
		for(int j=n;j>=0;--j){
			if (i==n&&j==n)f[i][j]=0;
			else
			f[i][j]=
			((double)(n-i)*(n-j)/(n*n)*f[i+1][j+1]+
			(double)(n-i)*j/(n*n)*f[i+1][j]+
			(double)i*(n-j)/(n*n)*f[i][j+1]+1)/(1-(double)i*j/(n*n));
		}
	}
	printf("%.6f",f[r][c]);
	return 0;
}