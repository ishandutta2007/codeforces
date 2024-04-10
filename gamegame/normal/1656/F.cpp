#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=998244353;
ll n;
ll a[N];
ll f(ll t){
	ll ans=a[1]*a[n]+t*(a[1]+a[n]);
	for(int i=2; i<=n-1 ;i++){
		ll w1=a[1]*a[i]+t*(a[1]+a[i]);
		ll wn=a[n]*a[i]+t*(a[n]+a[i]);
		ans+=min(w1,wn);
	}
	return ans;
}
void solve(){
	ll l=-1e12,r=1e12;
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	ll mn=0,mx=0;
	for(int i=2; i<=n ;i++){
		mn+=a[i]+a[1];
		mx+=a[i-1]+a[n];
	}
	if(mx<0 || mn>0){
		cout << "INF\n";
		return;
	}
	while(l!=r){
		ll m=l+(r-l)/2;
		if(f(m)<f(m+1)) l=m+1;
		else r=m;
	}
	cout << f(l) << '\n';
	
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}