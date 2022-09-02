#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000009
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n,a,b,k;
ll s[1000005];
string str;
ll modpow(ll x,ll n){
    x = (x%mod+mod)%mod;
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&a,&b,&k);
	cin>>str;
	ll ans=0;
	for(int i=0;i<k;i++){
	    if(i>n) break;
		ll base = (str[i]=='+'?1:-1);
		ll beg = i;
		ll en = (n-i)/k*k+beg;
		ll coef = (modpow(b,k)*modpow(modpow(a,k),mod-2)%mod);
		coef = (coef%mod+mod)%mod;
		if(coef == 1){
			ll num = (n-i)/k+1;
			ans+=base*num*modpow(a,n-i)%mod*modpow(b,i)%mod;
		}
		else{
			ll up = modpow(a,n-i)*modpow(b,i)%mod;
			up -= modpow(a,n-en)*modpow(b,en)%mod*coef%mod;
			up%=mod;
			ll down = modpow(1-coef,mod-2);
			up = up*down%mod;
			ans += up*base%mod;
		}
		ans%=mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}