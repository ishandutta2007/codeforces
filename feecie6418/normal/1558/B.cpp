#include<bits/stdc++.h>
using namespace std;
int mod,n,s[4000005],f[4000005],c[4000005];
int main(){
	cin>>n>>mod,f[1]=1;
	for(int i=1;i<=n;i++){
		c[i]=(c[i]+c[i-1])%mod;
		f[i]=(f[i]+s[i-1])%mod;
		f[i]=(f[i]+c[i])%mod;
		s[i]=(s[i-1]+f[i])%mod;
		for(int j=i+i,t=2;j<=n;j+=i,t++){
			int l=j,r=min(j+t-1,n);
			c[l]=(c[l]+f[i])%mod;
			c[r+1]=(c[r+1]-f[i]+mod)%mod;
		}
	}
	cout<<f[n];
}