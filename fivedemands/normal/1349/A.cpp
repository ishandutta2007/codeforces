#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e5+1;
int n;
int a[200001];
int pg[200001],sg[200002];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
ll lcm(ll x,ll y){
	return x*y/gcd(x,y);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		pg[i]=gcd(pg[i-1],a[i]);
	}
	for(int i=n; i>=1 ;i--){
		sg[i]=gcd(sg[i+1],a[i]);
	}
	ll ans=1;
	for(int i=1; i<=n ;i++){
		ans=lcm(ans,gcd(pg[i-1],sg[i+1]));
	}
	cout << ans << '\n';
}