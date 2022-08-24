#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[200001];
void solve(){
	int n,k1,k2;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	for(int i=2; i<=n ;i++){
		if(abs(a[i]-a[i-1])>=2){
			cout << "YES\n";
			cout << i-1 << ' ' << i << '\n';
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}