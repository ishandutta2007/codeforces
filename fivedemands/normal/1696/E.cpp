#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
const int iu=1e6;
int n;
int a[N];
ll f[N],inf[N];
vector<int>kill[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C(ll x,ll y){
	return f[x]*inf[x-y]%mod*inf[y]%mod;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=0; i<=n ;i++) cin >> a[i];
	f[0]=1;
	for(int i=1; i<=iu ;i++) f[i]=f[i-1]*i%mod;
	inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	ll ans=0;
	for(int i=0; i<=n ;i++){
		ans=(ans+C(i+a[i],i+1))%mod;
	}
	cout << ans << '\n';
	
}