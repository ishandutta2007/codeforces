#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int mod=1e9+7;
const int inv2=(mod+1)/2;
int fac[N],ifac[N],inv[N];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}	
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
	inv[1]=1;
	for(int i=2;i<=n;++i){
		inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
	}
}
inline int C(int n,int m){
	if(n<0||m<0||n<m)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(1000005);
	int T;
	cin>>T;
	while(T--){
		int n,m,k;
		cin>>n>>m>>k;
		if(n==m){
			cout<<1LL*n*k%mod<<'\n';
			continue;
		}
		int ans=0;
		for(int i=1;i<=m;++i){
			ans=(ans+1LL*C(n-i-1,m-i)*i%mod*qpow(inv2,n-i))%mod;
		}
		cout<<1LL*ans*k%mod<<'\n';
	}
	return 0;
}