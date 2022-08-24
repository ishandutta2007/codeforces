#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
ll n,s;
ll w[100001];
ll l,r;
ll ql,qr;
ll pf[100001];
void solve(){
	cin >> n >> l >> r >> ql >> qr;
	for(int i=1; i<=n ;i++){
		cin >> w[i];
		pf[i]=pf[i-1]+w[i];
	}
	ll ans=1e18;
	for(int i=0; i<=n ;i++){
		int lh=i,rh=n-i;
		ll ex=max(0,lh-rh-1)*ql+max(0,rh-lh-1)*qr;
		ll c=pf[lh]*l+(pf[n]-pf[lh])*r+ex;
		ans=min(ans,c);
	}
	cout << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}