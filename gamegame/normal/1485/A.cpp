#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n >> m;
	ll ans=1e18;
	for(ll i=0; i<=ans ;i++){
		if(m+i==1) continue;
		ll z=n;
		ll cur=0;
		while(z>0){
			cur++;
			z/=m+i;
		}
		ans=min(ans,cur+i);
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}