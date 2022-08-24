#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n;
int kk;
int ptr=0;
ll pf[101];
int deg[101];
int f[101];
ll inv[101];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> kk;
	for(ll i=2; i*i<=n ;i++){
		if(n%i!=0) continue;
		pf[++ptr]=i;
		deg[ptr]=0;
		while(n%i==0){
			n/=i;deg[ptr]++;
		}
	}
	for(int i=1; i<=100 ;i++){
		inv[i]=pw(i,mod-2);
	}
	if(n!=1){
		pf[++ptr]=n;
		deg[ptr]=1;
	}
	ll ans=1;
	for(int i=1; i<=ptr ;i++){
		f[deg[i]]=1;
		for(int j=0; j<deg[i] ;j++) f[j]=0;
		for(int j=1; j<=kk ;j++){
			for(int k=0; k<=deg[i] ;k++){
				for(int l=0; l<k ;l++) f[l]=(f[l]+f[k]*inv[k+1])%mod;
				f[k]=(f[k]*inv[k+1])%mod;
			}
		}
		ll sum=0;
		ll cur=1;
		for(int j=0; j<=deg[i] ;j++){
			sum=(sum+cur*f[j])%mod;
			cur=pf[i]%mod*cur%mod;
		}
		ans=ans*sum%mod;
	}
	cout << ans << endl;
}