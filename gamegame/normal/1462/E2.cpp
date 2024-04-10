#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
typedef double dd;
int n,m,k;
int a[N];
int p[N];
ll f[N],inf[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C(ll x,ll y){
	if(x<y) return 0;
	return f[x]*inf[y]%mod*inf[x-y]%mod;
}
void solve(){
	cin >> n >> m >> k;
	for(int i=1; i<=n ;i++) a[i]=0;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;a[x]++;
	}
	for(int i=1; i<=n ;i++) p[i]=p[i-1]+a[i];
	ll ans=0;
	k++;
	for(int i=k; i<=n ;i++){
		ans+=C(p[i]-p[i-k],m);
	}
	if(k>n-1){
		ans=C(p[n],m);
		cout << ans << '\n';
		return;
	}
	for(int i=k; i<=n-1 ;i++){
		ans-=C(p[i]-p[i-k+1],m);
	}
	ans%=mod;
	ans=(ans+mod)%mod;
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int iu=2e5;
	f[0]=1;
	for(int i=1; i<=iu ;i++) f[i]=i*f[i-1]%mod;
	inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	int t;cin >> t;while(t--) solve();
}