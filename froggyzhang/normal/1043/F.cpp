#include<bits/stdc++.h>
using namespace std;
#define N 300030
const int mx=300000;
const int mod=998244353;
typedef long long ll;
int n,a[N],f[N],cnt[N];
int fac[N],ifac[N];
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
}
int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(mx);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		++cnt[a[i]];
	}
	for(int i=1;i<=mx;++i){
		for(int j=i+i;j<=mx;j+=i){
			cnt[i]+=cnt[j];	
		}	
	}
	for(int ans=1;ans<=7;++ans){
		for(int i=1;i<=mx;++i){
			f[i]=C(cnt[i],ans);
		}
		for(int i=mx;i>=1;--i){
			for(int j=i+i;j<=mx;j+=i){
				f[i]=(f[i]+mod-f[j])%mod;
			}	
		}
		if(f[1]){
			cout<<ans<<'\n';
			return 0;	
		}
	}
	cout<<-1<<'\n';
	return 0;
}