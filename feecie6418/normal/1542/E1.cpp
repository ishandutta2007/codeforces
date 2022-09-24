#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,mod,f[2605],s[2605],ans[55];
inline int F(int x){
	if(x<0)x+=mod;
	return x;
}
inline int G(int x){
	if(x>=mod)x-=mod;
	return x;
}
int main(){
	cin>>n>>mod;
	f[0]=s[0]=1;
	for(int i=0;i<=2600;i++)s[i]=1;
	for(int i=1,cur=0;i<n;i++){
		for(int j=0;j<=cur;j++){
			if(j-i>=0)f[j]=F(s[j]-s[j-i]);
			else f[j]=s[j];
		}
		cur+=i;
		for(int j=0;j<=cur;j++)s[j]=G((j?s[j-1]:0)+f[j]);
		for(int j=0;j<=cur;j++){
			if(j-i>=0)f[j]=F(s[j]-s[j-i]);
			else f[j]=s[j];
		}
		cur+=i;
		for(int j=0;j<=cur;j++)s[j]=G((j?s[j-1]:0)+f[j]);
		for(int j=1;j<=i;j++)if(i*(i-1)/2+j<i*(i+1))ans[i+1]=(ans[i+1]+1ll*(i-j+1)*(s[i*(i+1)]-s[i*(i-1)/2+j]+mod))%mod;
	}
	for(int i=2;i<=n;i++)ans[i]=(ans[i]+1ll*i*ans[i-1])%mod;
	cout<<ans[n];
}