#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N];
ll dp[N][2];
int f[N][2];
bool prime(ll x){
	if(x==1) return false;
	for(int i=2; i*i<=x ;i++){
		if(x==i) return true;
		if(x%i==0) return false;
	}
	return true;
}
bool solve(){
	cin >> n;
	if(n==1) return false;
	if(n==2) return true;
	if(n%2==1) return true;
	if((n&-n)==n) return false;
	if(n%4!=0 && prime(n/2)) return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;
	while(t--){
		if(solve()) cout << "Ashishgup\n";
		else cout << "FastestFinger\n";
	}
}