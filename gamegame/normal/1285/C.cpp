#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int>v;
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
int main(){
	ios::sync_with_stdio(false);
	ll x;
	cin >> x;
	ll ax,ay;
	for(ll i=1; i*i<=x ;i++){
		if(x%i!=0) continue;
		if(gcd(i,x/i)!=1) continue;
		ax=i,ay=x/i;
	}
	cout << ax << ' ' << ay << endl;
}