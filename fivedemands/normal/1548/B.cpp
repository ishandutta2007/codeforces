#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N];
ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(n==1){
		cout << "1\n";
		return;
	}
	vector<pair<ll,int> >v;
	v.push_back({abs(a[2]-a[1]),1});
	int ans=1+(v[0].fi>1);
	for(int i=3; i<=n ;i++){
		ll duh=abs(a[i]-a[i-1]);
		for(int i=v.size()-1; i>=0 ;i--){
			duh=gcd(duh,v[i].fi);
			v[i].fi=duh;
		}
		v.push_back({abs(a[i]-a[i-1]),i-1});
		vector<pair<ll,int> >nv;
		for(auto c:v){
			if(nv.empty() || nv.back().fi!=c.fi) nv.push_back(c);
		}
		v=nv;
		if(v[0].fi!=1) ans=max(ans,i);
		else if(v.size()>=2){
			ans=max(ans,i-v[1].se+1);
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t; while(t--) solve();
	//solve();
}