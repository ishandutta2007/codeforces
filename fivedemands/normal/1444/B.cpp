#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n,m;
ll a[N],b[N];
ll f[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return pw(x,y-1)*x%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	f[0]=1;
	for(int i=1; i<=2*n ;i++){
		cin >> a[i];
		f[i]=i*f[i-1]%mod;
	}
	sort(a+1,a+2*n+1);
	ll ans=0;
	for(int i=1; i<=2*n ;i++){
		if(i<=n) ans-=a[i];
		else ans+=a[i];
	}
	ans%=mod;
	ll tmp=pw(f[n],mod-2);
	cout << ans*f[2*n]%mod*tmp%mod*tmp%mod << '\n';
}