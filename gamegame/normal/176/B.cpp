#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
int k;
string s,t;
const ll mod=1e9+7;
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin >> s >> t >> k;
	t+=t;
	n=s.size();
	int m=0;
	ll ans=0;
	for(int i=0; i<n ;i++){
		bool ok=true;
		for(int j=0; j<n ;j++){
			if(s[j]!=t[j+i]) ok=false;
		}
		if(!ok) continue;
		if(i==0){
			if(k%2==0) ans=ans+(pw(n-1,k)%mod+(n-1))*pw(n,mod-2);
			else ans=ans+(pw(n-1,k)%mod-(n-1))*pw(n,mod-2);
		}
		else{
			if(k%2==0) ans=ans+(pw(n-1,k)%mod-1)*pw(n,mod-2);
			else ans=ans+(pw(n-1,k)%mod+1)*pw(n,mod-2);
		}
		ans%=mod;
	}
	cout << ans << endl;
}