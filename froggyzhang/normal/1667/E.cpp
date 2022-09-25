#include<bits/stdc++.h>
using namespace std;
#define N 200020
const int mod=998244353;
typedef long long ll;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,fac[N],ifac[N],ans[N],tmp[N];
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int k=2;k<=(n+1)/2;++k){
		ans[k]=1LL*(C(n-1,k-1)-C((n+1)/2-1,k-1)+mod)*fac[k-2]%mod*fac[n-k]%mod;
		tmp[k]=1LL*C((n+1)/2-1,k-1)*fac[k-2]%mod*fac[n-k]%mod;
		/*
		for(int j=(n+1)/2;j<=n;++j){
			ans[k]=(ans[k]+1LL*C(n-k,j-k+1)*fac[j-1]%mod*fac[n-j-1])%mod;
		}
		*/
		ans[k]=1LL*ans[k]*(k-1)%mod;
	}
	int now=0;
	for(int k=(n+1)/2;k>=1;--k){
		ans[k]=(ans[k]+now)%mod;
		ans[k]=(fac[n-1]-ans[k]+mod)%mod;
		now=(now+tmp[k])%mod;
	}
	for(int k=1;k<=n;++k){
		cout<<ans[k]<<' ';
	}
	return 0;
}