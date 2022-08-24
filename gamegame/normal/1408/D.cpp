#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll x[N],y[N];
pair<ll,ll>s[N];
vector<pair<ll,ll> >v;
vector<pair<ll,ll> >g;
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> x[i] >> y[i];
	}
	for(int i=1; i<=m ;i++){
		cin >> s[i].fi >> s[i].se;
	}
	sort(s+1,s+m+1);
	for(int i=1; i<=m ;i++){
		while(!v.empty() && v.back().se<=s[i].se) v.pop_back();
		v.push_back(s[i]);
	}
	for(int i=1; i<=n ;i++){
		for(int j=0; j<v.size() ;j++){
			if(v[j].fi<x[i]) continue;
			g.push_back({max(0LL,v[j].fi-x[i]),v[j].se-y[i]+1});
		}
	}
	if(g.empty()){
		cout << "0\n";
		return;
	}
	sort(g.begin(),g.end());
	ll mx=0;
	reverse(g.begin(),g.end());
	ll ans=1e18;
	for(auto c:g){
		//cout << c.fi << ' ' << c.se << endl;
		ans=min(ans,c.fi+1+mx);
		mx=max(mx,c.se);
		//cout << ans << endl;
	}
	ans=min(ans,mx);
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	//int t;cin >> t;while(t--) solve();
	solve();
}