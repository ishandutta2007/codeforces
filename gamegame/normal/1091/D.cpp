#include<iostream>
using namespace std;
typedef long long ll;
ll mod=998244353;
int n;
ll f[1000001];
ll inf[1000001];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	f[0]=1;
	for(int i=1; i<=n ;i++) f[i]=f[i-1]*i%mod;
	inf[n]=pw(f[n],mod-2);
	for(int i=n; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	ll cur=1;
	ll ans=f[n];
	for(int i=0; i<n ;i++){
		cur=cur*(n-i)%mod;
		ans+=(f[n]-cur+mod)%mod;
		ans%=mod;
	}
	cout << ans << endl;
}