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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll n,ans,all;
ll f2(ll v){
	return (v%mod)*((v+1)%mod)%mod*((2*v+1)%mod)%mod*(mod+1)/6%mod;
}
ll f4(ll v){
	ll ret = (v%mod)*((v+1)%mod)%mod*((2*v+1)%mod)%mod*(3*(v%mod)*(v%mod)%mod+3*(v%mod)%mod-1)%mod;
	ret *= (mod*7LL+1)/30;
	return ret%mod;
}
ll f6(ll v){
	ll ret = (v%mod)*((v+1)%mod)%mod*((2*v+1)%mod)%mod*(3*(v%mod)*(v%mod)%mod*(v%mod)%mod*(v%mod)%mod+6*(v%mod)%mod*(v%mod)%mod*(v%mod)%mod-3*(v%mod)%mod+1)%mod;
	ret *= (mod+1)/42;
	return ret%mod;
}
int main(){
	cin>>n;
	ll rev = (mod+1)/6,ans = 0;
	for(ll a=-2000000LL;a<=2000000LL;a++){
		ll zan = n-a*a;
		if(zan < 0) continue;
		ll lb = 0,ub = 2000000LL;
		while(ub-lb>1){
			ll mid = (lb+ub)/2;
			if(mid*mid<=zan) lb = mid;
			else ub = mid;
		}
		ll zero = 0,two = 0,four = 0,six = 0;
		zero += (n%mod)*(n%mod)%mod*(n%mod)%mod;
		zero += 3*(n%mod)*(n%mod)%mod;
		zero -= 3*a%mod*a%mod*a%mod*a%mod*(n%mod)%mod;
		zero += 3*a%mod*a%mod*(n%mod)%mod;
		zero += 2*(n%mod);
		zero += 4*a%mod*a%mod;
		zero -= 6*a%mod*a%mod*a%mod*a%mod;
		zero += 2*a%mod*a%mod*a%mod*a%mod*a%mod*a%mod;
		zero = zero%mod*rev%mod*(2*lb+1)%mod;
		two -= 6*a%mod*a%mod*(n%mod)%mod;
		two += 3*(n%mod)%mod;
		two += 4;
		two -= 12*a%mod*a%mod;
		two += 6*a%mod*a%mod*a%mod*a%mod;
		two = two%mod*rev%mod*2%mod*f2(lb)%mod;
		four -= 3*(n%mod)%mod;
		four -= 6;
		four += 6*a%mod*a%mod;
		four = four%mod*rev%mod*2%mod*f4(lb)%mod;
		six += 2;
		six = six*rev%mod*2%mod*f6(lb)%mod;
		ans += zero+two+four+six;
		ans %= mod;
	}
	cout << (ans%mod+mod)%mod << endl;
}