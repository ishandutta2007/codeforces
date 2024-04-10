#include<bits/stdc++.h>//real solution
using namespace std;
typedef long long ll;
ll cal(ll a,ll b,ll c,ll n){
    if(n==0) return 0;
    return (b/c)*n+(a/c)*n*(n-1)/2+cal(c,(a*n+b)%c,a%c,(a%c*n+b%c)/c);
}
ll a,b,p,q;
ll cnt(ll l,ll r,ll vl,ll vr){
	ll sum=cal(p,l*p+q-vl,q,r-l+1)-cal(p,l*p+q-vr-1,q,r-l+1);
	return sum;
}
ll solve(){
	cin >> a >> b >> p >> q;
	ll l=0,r=q/2;
	while(l!=r){
		ll mid=(l+r)/2;
		ll bruh=cnt(a,b,q/2-mid,(q+1)/2+mid);
		if(bruh>0) r=mid;
		else l=mid+1;
	}
	ll gd=l;
	l=a,r=b;
	while(l!=r){
		ll mid=(l+r)/2;
		ll bruh=cnt(a,mid,q/2-gd,(q+1)/2+gd);
		if(bruh>0) r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
    int t;cin >> t;
    while(t--) cout << solve() << '\n';
}