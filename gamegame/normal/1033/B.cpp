#include<iostream>
using namespace std;
typedef long long ll;
bool check(ll num){
	for(int i=2; i<=min(num-1,1000000LL) ;i++){
		if(num%i==0) return false;
	}
	return true;
}
int main(){
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		ll a,b;
		cin >> a >> b;
		if(a!=b+1){
			cout << "NO\n";
			continue;
		}
		if(check(a+b)) cout << "YES\n";
		else cout << "NO\n";
	}
}