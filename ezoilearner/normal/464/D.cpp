#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef double db;
int n,k;
#define Maxn 100010
db f[2][605];
int main(){
	scanf("%d%d",&n,&k);
	int pre=0,now;
	for(int i=1;i<=600;++i)f[pre][i]=0;
	for(int i=n-1;i>=0;--i){
		now=pre^1;
		for(int j=1;j<=600;++j){
			f[now][j]=1.0/k*1.0/(j+1)*(j*(j+1)/2.0+j*f[pre][j]);
			f[now][j]+=1.0/k*1.0/(j+1)*(j+f[pre][j+1]);
			f[now][j]+=1.0*(k-1)/k*f[pre][j];
		}
		pre=now;
	}
	db Ans=f[now][1]*k;
	printf("%.10lf\n",Ans);
	return 0;
}