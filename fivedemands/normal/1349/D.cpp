#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int iu=2004;
#define fi first
#define se second
const ll mod=998244353;
int n;
ll dp[300001];
ll m[300001],c[300001];
ll a[300001];
ll s=0;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		s+=a[i];
	}
	ll invs=pw(s,mod-2);
	ll invm=pw(n-1,mod-2);
	for(int i=0; i<s ;i++){
		ll mg,cg;
		if(i==0) mg=(s-i)*invs%mod*(n-2)%mod*invm%mod;
		else mg=(i*invs%mod)*m[i-1]%mod+(s-i)*invs%mod*(n-2)%mod*invm%mod;
		if(i==0) cg=1;
		else cg=(1+(i*invs%mod)*c[i-1])%mod;
		ll bg=pw(mod+1-mg%mod,mod-2);
		c[i]=cg*bg%mod;
		m[i]=(s-i)*invs%mod*invm%mod*bg%mod;
	}
	for(int i=s-1; i>=0 ;i--){
		dp[i]=dp[i+1]*m[i]+c[i];
		dp[i]%=mod;
	}
	ll luda=0;
	for(int i=1; i<=n ;i++){
		luda+=dp[a[i]];
		luda%=mod;
	}
	ll bona=((n-1)*dp[0])%mod;
	ll ans=(luda-bona+mod)%mod;
	ans=ans*pw(n,mod-2)%mod;
	cout << ans << endl;
	//cout << bona << ' ' << luda << endl;
}