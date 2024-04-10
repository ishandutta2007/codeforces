#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	ll ma=1e18;
	ll mb=1e18;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		ma=min(ma,a[i]);
		mb=min(mb,b[i]);
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		ans+=max(a[i]-ma,b[i]-mb);
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
	
}