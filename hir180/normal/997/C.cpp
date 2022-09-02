#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll modpow(ll x,ll n){
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod;
		x=x*x%mod;
		n>>=1;
	}
	return res;
}
ll F[1000005],R[1000005];
void make(){
	F[0] = 1;
	for(int i=1;i<1000005;i++) F[i] = F[i-1]*i%mod;
	for(int i=0;i<1000005;i++) R[i] = modpow(F[i],mod-2);
}
ll C(int a,int b){
	return F[a]*R[b]%mod*R[a-b]%mod;
}
int main(){
	cin>>n;
	make();
	ll ans = modpow(modpow(3LL,n),n)-modpow((modpow(3LL,n)+mod-3)%mod,n)+mod;
	ans%=mod;
	for(int i=1;i<=n;i++){
		ll add = C(n,i);
		if(i%2 == 0) add = mod-add;
		ll add2 = modpow(3LL,i)+mod-3;
		add2 %= mod;
		add2 = add2*modpow(modpow(3LL,n-i),n)%mod;
		ll add3 = 3LL;
		add3 = add3*modpow(modpow(3LL,n-i)-1,n)%mod;
		add2 = (add2+add3)%mod;
		add = add*add2%mod;
		ans=(ans+add)%mod;
	}
	cout<<(ans%mod+mod)%mod<<endl;
}