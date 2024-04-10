#include<bits/stdc++.h>
using namespace std;
#define N 5005
const int mod=1e9+7;
const int inv2=(mod+1)/2;
typedef long long ll;
int n,a[N],s[N],invs[N],t[N<<1][N],g[N<<2];
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	--n;
	s[0]=1;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=1LL*s[i-1]*a[i]%mod;
	}
	for(int i=0;i<=n;++i){
		invs[i]=qpow(s[i],mod-2);
	}
	for(int i=0;i<=n;++i){
		for(int j=0;j<=n;++j){
			g[i+j]=(g[i+j]+1LL*s[i]*s[j])%mod;
		}
	}
	for(int i=0;i<=n;++i){
		for(int k=0;k<=2*n;++k){
			t[k][i]=1LL*g[k+2*i]*invs[i]%mod;
		}
		g[i<<1]=(g[i<<1]+1LL*(mod-s[i])*s[i])%mod;
		for(int j=2*i+1;j<=n+i;++j){
			g[j]=(g[j]+2LL*(mod-s[i])*s[j-i])%mod;
		}
	}
	for(int k=2*n;k>=2;--k){
		for(int i=0;i<=n;++i){
			t[k][i]=(t[k][i]-t[k-2][i+1]+mod)%mod;
		}
	}
	for(int k=1;k<=2*n;++k){
		int ans=0;
		for(int i=0;i<=n;++i){
			ans=(ans+t[k][i])%mod;
		}
		cout<<1LL*ans*inv2%mod<<' ';
	}
	return 0;
}