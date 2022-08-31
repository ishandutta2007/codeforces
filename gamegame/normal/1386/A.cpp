#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;

int ask(ll x){
	cout << "? " << x << endl;
	int y;cin >> y;return y;
}
ll f(ll x){
	if(x==0) return 1;
	if(x==1) return 1;
	return (x)/2-f((x)/2)+2;
}
void solve(){
	cin >> n;
	if(n==1){
		cout << "= 1" << endl;
		return;
	}
	ll y=(n+1)/2;
	ll x=f(n-y-1);
	ask(x+y);
	int z=ask(x);
	ll l=1,r=y;
	if(!z) l=y+1,r=n;
	bool lf=true;
	while(l!=r){
		ll mid=(l+r)/2;
		if(l%2==r%2 && l>=y) mid--;
		if(lf){
			if(x+mid<=n) x+=mid;
			else x-=mid;
		}
		else{
			if(x-mid>0) x-=mid;
			else x+=mid;
		}
		lf^=1;
		z=ask(x);
		if(z) r=mid;
		else l=mid+1;
	}
	cout << "= " << l << endl;
	return;
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}