#include<bits/stdc++.h>
using namespace std;
#define N 200020
typedef long long ll;
const int mod=998244353;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,K,mu[N],fac[N],ifac[N];
int zz[N];
void init(int n){
	mu[1]=1;
	for(int i=1;i<=n;++i)
		for(int j=i+i;j<=n;j+=i)
			mu[j]-=mu[i];
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
	zz[0]=1;
	for(int i=1;i<=n;++i){
		zz[i]=(zz[i-1]+(i&1?mod-ifac[i]:ifac[i]))%mod;
	}
}
int sum_S2(int n,int m){ // S2(n,0)+S2(n,1)+...+S2(n,m)
	m=min(m,n);
	int tot=0;
	for(int j=0;j<=m;++j){
		tot=(tot+1LL*zz[m-j]*qpow(j,n)%mod*ifac[j])%mod;
	}
	return tot;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>K;
	if(n==1||K==1){
		cout<<1<<'\n';
		return 0;
	}
	init(n);
	int ans=0;
	for(int i=1;i<=n;++i){
		ans-=mu[i];   // 
	}
	for(int i=1;i<=n;++i){ //  i 
		if(mu[i]){
			ans=(ans+sum_S2((n-1)/i+1,K)*mu[i])%mod;
		}
	}
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}