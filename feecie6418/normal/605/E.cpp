#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,used[1005];
double p[1005][1005],cur[1005],f[1005];
double Calc(int x){
	if(used[x])return f[x];
	return (f[x]+cur[x])/(1-cur[x]);
}
void Do(int x){
	used[x]=1;
	for(int i=1;i<=n;i++)if(!used[i])f[i]+=(f[x]+1)*p[i][x]*cur[i],cur[i]*=1-p[i][x];
}
int main(){
	scanf("%d",&n);
	if(n==1)return puts("0"),0;
	for(int i=1,x;i<=n;i++)for(int j=1;j<=n;j++)scanf("%d",&x),p[i][j]=x/100.0;
	for(int j=1;j<=n;j++)cur[j]=1;
	f[n]=0,Do(n);
	for(int i=1;i<n;i++){
		double mn=1e9;
		int p=0;
		for(int j=1;j<=n;j++)if(used[j]!=1&&(!p||Calc(j)<mn))p=j,mn=Calc(j);
		f[p]=Calc(p),Do(p);
		if(p==1)return printf("%.6lf\n",f[1]),0;
	}
}