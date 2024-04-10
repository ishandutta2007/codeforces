#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--){
		ll x;cin >> x;
		if(x<=14) cout << "NO\n";
		else if(x%14<7 && x%14!=0) cout << "YES\n";
		else cout << "NO\n";
	}
}