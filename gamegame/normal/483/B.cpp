#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	ll w,x,y,z;
	cin >> w >> z >> x >> y;
	ll l=1,r=2e9;
	while(l!=r){
		ll mid=(l+r)/2;
		ll d=mid/(x*y);
		ll c=mid/x-d;
		ll b=mid/y-d;
		ll a=mid-b-c-d;
		if(a+b<w || a+c<z || a+b+c<w+z) l=mid+1;
		else r=mid;
	}
	cout << l << endl;
}