#include<bits/stdc++.h>
using namespace std;
const int MX=1e7;
#define N 10000100
const int mod=998244353;
const int inv2=(mod+1)/2;
typedef long long ll;
int n,k,x,pw2[N];
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
	pw2[0]=1;
	for(int i=1;i<=n;++i){
		pw2[i]=(pw2[i-1]<<1)%mod;
	}	
}
void get_inv(int *a,int n){
	static int prod[N];
	prod[0]=1;
	for(int i=1;i<=n;++i){
		prod[i]=1LL*prod[i-1]*a[i]%mod;
	}
	prod[n]=qpow(prod[n],mod-2);
	for(int i=n;i>=1;--i){
		int t=a[i];
		a[i]=1LL*prod[i-1]*prod[i]%mod;
		prod[i-1]=1LL*prod[i]*t%mod;
	}
}
void Solve(){
	cin>>n>>k>>x;
	if(!x){
		if(n>k){
			cout<<0<<'\n';
			return;
		}
		int ans=1;
		for(int i=0;i<n;++i){
			ans=1LL*ans*(pw2[k]+mod-pw2[i])%mod;
		}
		cout<<ans<<'\n';
		return;
	}
	/*
	static int dp[2333][2333];
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	for(int i=2;i<=n+1;++i){
		for(int j=1;j<=i;++j){
			dp[i][j]=(1LL*dp[i-1][j]*pw2[j-1]+1LL*dp[i-1][j-1]*(pw2[k]-pw2[j-1]+mod))%mod;	
		}
	}
	int ans=0;
	for(int i=1;i<=n+1;++i){
		ans=(ans+dp[n+1][i])%mod;
	}
	cout<<ans<<'\n';
	*/
	int ans=0;
	static int pre[N],a[N],b[N];
	pre[1]=1;
	for(int i=2;i<=k;++i){
		pre[i]=1LL*pre[i-1]*(pw2[k]-pw2[i-1]+mod)%mod;	
	}
	for(int i=1;i<=k;++i){
		a[i]=pw2[i]-1;
	}
	get_inv(a,k);
	int now=1,jb=qpow(2,n);
	for(int r=1;r<=k;++r){
		ans=(ans+1LL*pre[r]*now)%mod;
		now=1LL*now*a[r]%mod;
		now=1LL*now*(jb-1)%mod;
		jb=1LL*jb*inv2%mod;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	init(MX);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}