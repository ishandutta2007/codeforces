#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve(){
	int n,k;
	cin >> n >> k;
	if(n%k>k/2) cout << n-(n%k-k/2) << '\n';
	else cout << n << '\n';
}
int a[1110001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}