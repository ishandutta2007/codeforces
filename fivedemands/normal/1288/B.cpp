#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	ll x,y;cin >> x >> y;
	ll cur=9;
	ll ans=0;
	while(true){
		if(cur>y) break;
		ans+=x;
		cur=cur*10+9;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}