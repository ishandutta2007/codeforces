#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	ll n,d;cin >> n >> d;
	ll x=sqrt(d);
	for(int i=max(1LL,x-2); i<=x+2 ;i++){
		if(i+(d+i)/(i+1)<=n || n>=d){
			cout << "YES\n";return;
		}
	}
	cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}