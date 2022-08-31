#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int n;
ll mod(ll m){
	return m%(ll)(1e9+7);
}
ll fact[200001],inv[200001];
ll inver(ll x){
	ll y=1e9+5;
	ll a[31];
	a[0]=x;
	for(int i=1; i<=30 ;i++){
		a[i]=mod(a[i-1]*a[i-1]);
	}
	ll ans=1;
	for(int i=0; i<=30 ;i++){
		if(y&(1<<i)){
			ans=mod(ans*a[i]);
		}
	}
	return ans;
}
ll c(int i,int j){
	return mod(mod(fact[i]*inv[j])*inv[i-j]);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	fact[0]=1;inv[0]=1;
	for(int i=1; i<=200000 ;i++){
		fact[i]=mod(fact[i-1]*i);
		inv[i]=inver(fact[i]);
	}
	cout << mod(c(2*n-1,n-1)*2-n+1e9+7);
}