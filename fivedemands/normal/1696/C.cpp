#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
void solve(){
	cin >> n >> m;
	vector<pair<ll,ll> >va,vb;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		ll cx=a[i],cy=1;
		while(cx%m==0){
			cx/=m;cy*=m;
		}
		if(!va.empty() && va.back().fi==cx) va.back().se+=cy;
		else va.push_back({cx,cy});
	}
	swap(va,vb);
	cin >> k;
	for(int i=1; i<=k ;i++){
		cin >> a[i];
		ll cx=a[i],cy=1;
		while(cx%m==0){
			cx/=m;cy*=m;
		}
		if(!va.empty() && va.back().fi==cx) va.back().se+=cy;
		else va.push_back({cx,cy});
	}
	if(va==vb) cout << "Yes\n";
	else cout << "No\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}