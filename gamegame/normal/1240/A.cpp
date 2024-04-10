#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll p[200001];
ll x,a,y,b;
ll k;
ll gcd(ll u,ll v){
	if(v==0) return u;
	return gcd(v,u%v);
}
ll solve(ll t){
	ll hx=t/x;
	ll hy=t/y;
	ll hz=t/((x*y)/gcd(x,y));
	hx-=hz;hy-=hz;
	ll sum=0;
	for(int i=n; i>n-hz ;i--){
		sum+=p[i]*(a+b)/100;
	}
	for(int i=n-hz; i>n-hz-hy ;i--){
		sum+=p[i]*(b)/100;
	}
	for(int i=n-hz-hy; i>n-hz-hy-hx ;i--){
		sum+=p[i]*a/100;
	}
	return sum;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> p[i];
	sort(p+1,p+n+1);
	cin >> x >> a >> y >> b >> k;
	
	swap(x,a);swap(y,b);
	if(b<a) swap(x,y),swap(a,b);
	ll l=1,r=n+1;
	while(l!=r){
		ll mid=(l+r)/2;
		if(solve(mid)<k) l=mid+1;
		else r=mid; 
	}
	if(r==n+1) cout << "-1\n";
	else cout << r << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int q;cin >> q;while(q--) solve();
}