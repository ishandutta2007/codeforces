#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,k;
ll sum(ll x,ll y){
	return (x+y)*(y-x+1)/2;
}
pair<ll,ll>g(ll w){//count,nearest
	if(w<k*(k+1)/2) return{0LL,(bool)0};
	ll r=(w+k*(k+1)/2-1)/k;
	auto c=g(r);
	ll d=c.fi;
	ll x=(r-d-1)/k;
	ll y=(r-d-1)%k;
	ll s=sum(r-y-1,r+k-y-1)-max(c.se,r-y-1);
	if(s<=w) return {x+1,s};
	if(c.se>=r-k){
		if(c.se>=r-y-1) c.se=0;
		r--,d--;
	}
	r-=k;
	x=(r-d-1)/k;
	y=(r-d-1)%k;
	if(c.se>=r) y--;
	s=sum(r-y-1,r+k-y-1)-max(c.se,r-y-1);
	//cout << "? " << w << ' ' << r << ' ' << x << ' ' << y << ' ' << s << endl;
	return {x+1,s};
	//consider sum of ro
}
void solve(){
	cin >> n >> k;
	ll d=g(n).fi;
	ll e=g(n-1).fi;
	if(e<d){
		cout << (k+1)*d << '\n';
		return;
	}
	ll x=(n-d-1)/k;
	ll y=(n-d-1)%k;
	cout << x*(k+1)+y+1 << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}