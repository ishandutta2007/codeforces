#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void solve(){
	ll p,q,b;
	cin >> p >> q >> b;
	ll g=gcd(p,q);
	p/=g;
	q/=g;
	g=gcd(q,b);
	while(g!=1){
		while(q%g==0) q/=g; 
		g=gcd(q,b);
	}
	if(q==1) cout << "Finite\n";
	else cout << "Infinite\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}