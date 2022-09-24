#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,s[2000005],f[2000005],g[2000005],sg[2000005];
int main(){
	cin>>n,n++,s[0]=f[0]=1;
	int u=0;
	for(int i=1;i<=n;i++){
		f[i]=1ll*f[i-1]*(f[i-1]+1)/2%mod;
		if(i>1)f[i]=(f[i]+1ll*f[i-1]*s[i-2])%mod;
		s[i]=(s[i-1]+f[i])%mod;
		if(i<n-1)u=(u+1ll*f[i]*(s[i-1]-1))%mod;
		g[i]=(f[i]-f[i-1]+mod)%mod,sg[i]=(sg[i-1]+g[i])%mod;
	}
	for(int i=1;i<n;i++)
		for(int j=i;j<n;j=(j!=n-1?n-1:n)){
			if(i==j&&j!=n-1)u=(u+1ll*f[i]*(f[i]+1)%mod*(mod+1)/2%mod)%mod;
			if(i!=j&&j==n-1)u=(u+1ll*f[i]*(f[n-1]+1)%mod*(mod+1)/2%mod)%mod;
			if(i==j&&j==n-1)u=(u+1ll*(f[i]+1)*(f[i]+2)%mod*(mod+1)/6)%mod;
		}
	int sum=(2ll*(f[n]+1ll*u*f[n-1])-1)%mod;
	for(int i=1;i<n;i++)sum=(sum+1ll*g[i+1]*sg[n-i-1])%mod;
	cout<<sum;
}