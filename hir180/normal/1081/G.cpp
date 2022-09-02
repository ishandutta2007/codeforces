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
//#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
map<int,int>M;
int n,k;
ll mod;
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
int main(){
	cin>>n>>k>>mod;
	if(k > 25){
		puts("0"); return 0;
	}
	int x = (1<<(k-1));
	if(n <= x){
		puts("0"); return 0;
	}
	for(int j=0;j<x;j++){
		int a = n/x;
		if(n%x > j) a++;
		M[a]++;
	}
	ll ans = 0;
	for(map<int,int>::iterator it=M.begin();it!=M.end();++it){
		for(map<int,int>::iterator it2=M.begin();it2!=M.end();++it2){
			if(it->fi > it2->fi) continue;
			ll coef;
			if(it->fi != it2->fi){
				coef = 2LL*(it->sc)*(it2->sc)%mod;
			}
			else{
				coef = 1LL*(it->sc)*(it2->sc-1)%mod;
			}
			{
				int a = it->fi;
				for(int i=2;i<=2*a;i++){
					if(i <= a+1){
						// (i-2)*(i-1)/(4*i)
						ans += coef*(i-2)%mod*(i-1)%mod*modpow(4LL*i%mod,mod-2)%mod;
					}
					else{
						// (i-2)*(2*a-i+1)/(4*i)
						ans += coef*(i-2)%mod*(2*a-i+1)%mod*modpow(4LL*i%mod,mod-2)%mod;
					}
				}
			}
			if(it->fi != it2->fi){
				for(int y=1;y<=it->fi;y++){
					ans += coef*(it->fi)%mod*modpow(it->fi+1+y,mod-2)%mod*modpow(4LL,mod-2)%mod;
				}
				for(int x=1;x<=it->fi;x++){
					ans += coef*(x-1)%mod*modpow(x+it->fi+1,mod-2)%mod*modpow(4LL,mod-2)%mod;
				}
			}
		}
	}
	for(map<int,int>::iterator it=M.begin();it!=M.end();++it){
	    ll a = (1LL*it->fi*(it->fi-1)/2)%mod;
		ans += a*modpow(2LL,mod-2)%mod*(it->sc)%mod;
	}
	cout<<ans%mod<<endl;
}