#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1001];
void solve(){
	cin >> n >> k;
	for(int i=1; i<=n ;i++) cin >> a[i];
	sort(a+1,a+n+1);
	if(a[n]-a[1]>2*k) cout << "-1\n";
	else cout << a[1]+k << '\n';
}
int main(){
    ios::sync_with_stdio(false);
    int t;cin >> t;while(t--) solve();
}