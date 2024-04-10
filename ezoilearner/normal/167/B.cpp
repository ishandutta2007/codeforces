#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
int n,L,K;
#define Maxn 205
db p[Maxn];
db f[2][Maxn][Maxn*2];
int a[Maxn];
int main(){
	scanf("%d%d%d",&n,&L,&K);
	for(int i=1;i<=n;++i)scanf("%lf",&p[i]),p[i]/=100.0;
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	int pre=0,now;
	f[pre][0][min(K,n+1)+n+1]=1;
	for(int i=1;i<=n;++i){
		now=pre^1;
		memset(f[now],0,sizeof(f[now]));
		for(int j=0;j<=n;++j)
		for(int k=1;k<=2*n+2;++k){
		f[now][j][k]+=f[pre][j][k]*(1-p[i]);
		f[now][j+1][k==2*n+2?k:min(2*n+2,k+a[i])]+=f[pre][j][k]*p[i];
	}
		pre=now;
	}
	db Ans=0;
	for(int i=L;i<=n;++i)
	for(int j=n+1;j<=2*n+2;++j)Ans=Ans+f[now][i][j];
	printf("%.6lf\n",Ans);
	return 0;
}