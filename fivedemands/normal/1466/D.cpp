#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m;
ll a[N],d[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		d[i]=0;
		cin >> a[i];
	}
	for(int i=1; i<n ;i++){
		int u,v;cin >> u >> v;
		d[u]++;d[v]++;
	}
	vector<ll>v;
	ll ans=0;
	for(int i=1; i<=n ;i++){
		for(int j=0; j<d[i]-1 ;j++) v.push_back(a[i]);
		ans+=a[i];
	}
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	cout << ans << ' ';
	for(auto c:v){
		ans+=c;
		cout << ans << ' ';
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}