#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll solve(){
	ll a,b,c,d;
	cin >> a >> b >> c >> d;
	if(a>b*c) return -1;
	ll l=0,r=c/d;
	while(l<r){
		ll x=(l+r)/2;
		ll y=x+1;
		ll fx=(x+1)*a-b*d*(x*(x+1))/2;
		ll fy=(y+1)*a-b*d*(y*(y+1))/2;
		if(fx<fy) l=x+1;
		else r=x;
	}
	ll x=l;
	ll fx=(x+1)*a-b*d*(x*(x+1))/2;
	return fx;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) cout << solve() << '\n';
}