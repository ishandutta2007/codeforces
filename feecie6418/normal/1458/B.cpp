#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,f[105][10005],sum=0;
struct Thing{
	int cur,all;
}a[105];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].all>>a[i].cur,sum+=a[i].cur;
	memset(f,0xc0,sizeof(f)),f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j>=1;j--){
			for(int k=10000;k>=a[i].all;k--)f[j][k]=max(f[j][k],f[j-1][k-a[i].all]+a[i].cur);
		}
	}
	for(int i=1;i<=n;i++){
		double p=0;
		for(int j=0;j<=10000;j++)p=max(p,min((f[i][j]+sum)/2.0,1.0*j));
		printf("%.15lf ",p);
	}
}