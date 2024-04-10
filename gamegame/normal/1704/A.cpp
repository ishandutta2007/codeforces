#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,m;
int a[51],b[51];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;a[i]=c-48;
	}
	for(int i=1; i<=m ;i++){
		char c;cin >> c;b[i]=c-48;
	}
	for(int i=2; i<=m ;i++){
		if(a[i+n-m]!=b[i]){
			cout << "NO\n";
			return;
		}
	}
	for(int i=1; i<=n-m+1 ;i++){
		if(a[i]==b[1]){
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}