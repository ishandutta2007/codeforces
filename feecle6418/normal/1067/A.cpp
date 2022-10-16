#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,a[100005],f[100005][205][2],s[100005][205][2],ans=0;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(a[1]==-1){
		for(int i=1;i<=200;i++)f[1][i][0]=1;
	}
	else {
		f[1][a[1]][0]=1;
	}
	for(int i=1;i<=200;i++)s[1][i][0]=(s[1][i-1][0]+f[1][i][0]);
	for(int i=2;i<=n;i++){
		if(a[i]!=-1){
			f[i][a[i]][0]=(s[i-1][a[i]-1][0]+s[i-1][a[i]-1][1])%mod;//a[i]>a[i-1]
			f[i][a[i]][1]=(s[i-1][200][1]-s[i-1][a[i]][1]+mod)%mod;//a[i]<a[i-1]
			f[i][a[i]][1]=(0ll+f[i][a[i]][1]+f[i-1][a[i]][0]+f[i-1][a[i]][1])%mod;//a[i]=a[i-1]
		}
		else {
			for(int j=1;j<=200;j++){
				f[i][j][0]=(s[i-1][j-1][0]+s[i-1][j-1][1])%mod;//a[i]>a[i-1]
				f[i][j][1]=(s[i-1][200][1]-s[i-1][j][1]+mod)%mod;//a[i]<a[i-1]
				f[i][j][1]=(0ll+f[i][j][1]+f[i-1][j][0]+f[i-1][j][1])%mod;//a[i]=a[i-1]
			}
		}
		for(int j=1;j<=200;j++)for(int k=0;k<2;k++)s[i][j][k]=(s[i][j-1][k]+f[i][j][k])%mod;
	}
	for(int i=1;i<=200;i++)ans=(ans+f[n][i][1])%mod;
	cout<<ans;
}