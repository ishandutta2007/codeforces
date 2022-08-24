#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
int n,m,p;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll f[N],inf[N];
const int iu=1e5;
void arin(){
	f[0]=1;
	for(int i=1; i<=iu ;i++) f[i]=f[i-1]*i%mod;
	inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
}
ll C(ll x,ll y){
	return f[x]*inf[x-y]%mod*inf[y]%mod;
}
void solve(){
	cin >> n >> m;
	ll ans=1;
	for(int i=1; i<=(n+m-1)/m ;i++){
		ll w1=C(n,i);
		ll w2=C(n-(i-1)*(m-1),i);
		ans=(ans+w2*pw(w1,mod-2))%mod;
	}
	cout << ans << '\n';
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	arin();
	int t;cin >> t;while(t--) solve();
}