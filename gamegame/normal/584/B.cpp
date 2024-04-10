#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
const ll mod=1e9+7;
int main(){
	ios::sync_with_stdio(false);
	ll x=1,y=1;
	cin >> n;
	for(int i=1; i<=n ;i++){
		x*=27,y*=7;
		x%=mod;y%=mod;
	}
	cout << (x-y+mod)%mod << endl;
}