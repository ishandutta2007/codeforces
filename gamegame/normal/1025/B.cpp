#include<iostream>
using namespace std;
typedef long long ll;
ll cur=0;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int n;
ll a[150001],b[150001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i] >> b[i];
		cur=gcd(cur,a[i]*b[i]);
	}
	if(cur==1){
		cout << "-1\n";
		return 0;
	}
	for(int i=1; i<=n ;i++){
		if(gcd(cur,a[i])!=1) cur=gcd(cur,a[i]);
		else cur=gcd(cur,b[i]);
	}
	cout << cur << endl;
}