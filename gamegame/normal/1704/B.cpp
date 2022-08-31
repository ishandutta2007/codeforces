#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll a[200001];
void solve(){
	int n;ll x;
	cin >> n >> x;
	ll l=2e9,r=-2e9;
	int ans=0;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		l=min(l,a[i]),r=max(r,a[i]);
		if(r-l>2*x){
			ans++;l=a[i];r=a[i];
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}