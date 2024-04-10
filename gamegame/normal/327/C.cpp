#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
string s;
ll k;
ll n;
int main(){
	ios::sync_with_stdio(false);
	cin >> s >> k;
	n=s.size();
	ll u=pw(2,n)-1;
	ll dumb=(pw(2,k*n)-1)*pw(u,mod-2)%mod;
	if(u==0) dumb=k;
	ll ans=0;
	for(int i=n-1; i>=0 ;i--){
		ans=ans*2%mod;
		if(s[i]=='5' || s[i]=='0') ans=(ans+dumb)%mod;
	}
	cout << ans << endl;
}