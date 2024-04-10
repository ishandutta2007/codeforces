#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=998244353;
#define fi first
#define se second
const int N=2e6+1;
ll n,m,k;
ll a[N],b[N];
ll c[N],d[N];
vector<ll>v[3],p[3];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	v[1].clear();v[2].clear();
	for(int i=1; i<=n ;i++){
		cin >> b[i];
		v[b[i]].push_back(a[i]);
	}
	sort(v[1].begin(),v[1].end());
	sort(v[2].begin(),v[2].end());
	reverse(v[1].begin(),v[1].end());
	reverse(v[2].begin(),v[2].end());
	p[1].resize(v[1].size()+1);
	p[2].resize(v[2].size()+1);
	for(int i=0; i<v[1].size() ;i++){
		p[1][i+1]=p[1][i]+v[1][i];
	}
	for(int i=0; i<v[2].size() ;i++){
		p[2][i+1]=p[2][i]+v[2][i];
	}
	ll ans=1e9;
	for(int i=0; i<=v[1].size() ;i++){
		if(p[1][i]+p[2].back()<m) continue;
		int l=0,r=v[2].size();
		while(l!=r){
			int mid=(l+r)/2;
			if(p[1][i]+p[2][mid]<m) l=mid+1;
			else r=mid;
		}
		//cout << i << ' ' << l << endl;
		ans=min(ans,(ll)i+2*l);
	}
	if(ans==1e9) cout << "-1\n";
	else cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}