#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,c[105],b[105],sb[105],f[105][10005],x,ans=0; 
int main(){
	cin>>n,f[0][0]=1;
	for(int i=1;i<=n;i++)cin>>c[i];
	for(int i=1;i<=n;i++){
		if(i<n)cin>>b[i];
		for(int j=1;j<i;j++)sb[i]+=(i-j)*b[j];
	}
	cin>>x,cin>>x;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=10000;j++){
			if(j<i*x+sb[i])continue;
			for(int k=0;k<=j&&k<=c[i];k++)f[i][j]=(f[i][j]+f[i-1][j-k])%mod;
		}
	}
	for(int j=0;j<=10000;j++)ans=(ans+f[n][j])%mod;
	cout<<ans;
}