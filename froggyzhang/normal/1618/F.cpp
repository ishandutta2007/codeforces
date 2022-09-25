#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y;
ll Rev(ll x){
	ll y=0;
	while(x)y=y<<1|(x&1),x>>=1;
	return y;	
}
ll D0(ll x){
	while(!(x&1))x>>=1;
	return x;	
}
bool check(ll x,ll y){
	ll jb=(1LL<<__lg(x)+1)-1;
	while(y){
		if((!((y^x)&jb))&&__lg(y)==__lg(x)+__builtin_popcountll(y^x))return true;
		if(!(y&1))break;
		y>>=1;	
	}
	return false;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>x>>y;
	cout<<(x==y||check(D0(x),y)||check(x<<1|1,y)||check(Rev(x),y)||check(Rev(D0(x)),y)||check(Rev(x<<1|1),y)?"YES\n":"NO\n");
	return 0;
}