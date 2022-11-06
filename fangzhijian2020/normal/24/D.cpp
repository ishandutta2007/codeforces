#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m,x,y;double k[1005],b[1005],f[2][1005];
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);n-=x;
	if(m==1)return printf("%.4lf",n*2.0),0;
	k[1]=0.5;for(int j=2;j<m;++j)k[j]=1.0/(3.0-k[j-1]);
	for(int i=n;i>=1;--i){
		b[1]=1.5+f[(i+1)&1][1]/2.0;
		for(int j=2;j<m;++j){
			b[j]=(4.0+f[(i+1)&1][j]+b[j-1])/(3.0-k[j-1]);
		}
		f[i&1][m]=(b[m-1]+f[(i+1)&1][m]+3.0)/(2.0-k[m-1]);
		for(int j=m-1;j;--j)f[i&1][j]=k[j]*f[i&1][j+1]+b[j];
	}
	printf("%.4lf\n",f[1][y]);
	return 0;
}