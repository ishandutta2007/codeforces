#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
const int iu=1e6+1;
ll n,m,k;
const ll mod=1e9+7;
ll f[iu+1],inf[iu+1];
ll p2[iu+1],ip2[iu+1];
ll C(ll x,ll y){
	return f[x]*inf[y]%mod*inf[x-y]%mod;
}
void solve(){
	cin >> n >> m >> k;
	ll ans=0;
	for(int i=1; i<=m ;i++){
		//cout << i << ' ' << p2[i] << end;
		ans=ans+C(n-i,m-i)*p2[i-1]%mod*(i+1)%mod;
		ans%=mod;
	}
	ans=ans*ip2[n]%mod*k%mod;
	cout << ans << '\n';
}
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	p2[0]=f[0]=1;
	for(int i=1; i<=iu ;i++){
		p2[i]=p2[i-1]*2%mod;
		f[i]=f[i-1]*i%mod;
	}
	ip2[iu]=pw(p2[iu],mod-2);inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--){
		ip2[i-1]=ip2[i]*2%mod;
		inf[i-1]=inf[i]*i%mod;
	}
	int t;cin >> t;
	while(t--) solve();
}