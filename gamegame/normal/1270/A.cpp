#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n,k1,k2;
	cin >> n >> k1 >> k2;
	int a=0,b=0,c=0;
	for(int i=1; i<=k1 ;i++){
		int x;cin >> x;
		a=max(a,x);b=max(b,x);
	}
	for(int i=1; i<=k2 ;i++){
		int x;cin >> x;
		a=max(a,x);c=max(c,x);
	}
	if(a==b) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}