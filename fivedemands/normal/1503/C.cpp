#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const ll N=2e6+1;
int n;
pair<ll,ll>a[N];
ll ans=0;

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi >> a[i].se;
		ans+=a[i].se;
	}
	sort(a+1,a+n+1);
	vector<int>use;
	vector<ll>bse;
	ll mx=-1;
	for(int i=1; i<=n ;i++){
		if(a[i].fi>mx){
			use.push_back(i-1);
			bse.push_back(mx);
		}
		mx=max(mx,a[i].fi+a[i].se);
	}
	use.push_back(n);
	for(int i=2; i<use.size() ;i++){
		ans+=a[use[i-1]+1].fi-bse[i-1];
	}
	cout << ans << '\n';
}