#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[100001];
void solve(){
	cin >> n;
	ll pf=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=1; i<n ;i++){
		pf+=a[i];
		if(pf<=0){
			cout << "NO\n";return;
		}
	}
	pf=0;
	for(int i=n; i>1 ;i--){
		pf+=a[i];
		if(pf<=0){
			cout << "NO\n";return;
		}
	}
	cout << "YES\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}