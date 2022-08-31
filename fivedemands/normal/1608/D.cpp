#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int iu=2e5;
const int N=2e5+1;
ll n;
ll f[N],inf[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	//cout << x << ' ' << y/2 << ' ' << res << endl;
	return res*res%mod;
}
ll fun=1;
ll v1=1,v2=1;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	int cb=0,cw=0;
	for(int i=1; i<=n ;i++){
		string s;cin >> s;
		for(auto c:s){
			cb+=(c=='B');
			cw+=(c=='W');
		}
		if(s[0]=='B' || s[1]=='W') v1=0;
		if(s[0]=='W' || s[1]=='B') v2=0;
		if(s[0]=='?' && s[1]=='?') fun=fun*2%mod;
		else if(s[0]==s[1]) fun=0;
	}
	//cout << fun << endl;
	f[0]=1;
	for(int i=1; i<=2*n ;i++) f[i]=f[i-1]*i%mod;
	inf[2*n]=pw(f[2*n],mod-2);
	for(int i=2*n; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	if(cb>n || cw>n) return cout << "0\n",0;
	ll ans=f[2*n-cb-cw]*inf[n-cb]%mod*inf[n-cw]%mod;
	ans=(ans+mod-fun+v1+v2)%mod;
	cout << ans << '\n';
}