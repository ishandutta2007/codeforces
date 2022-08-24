#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,p,k;
ll x,y;
ll v[N];
char c[N];
void solve(){
	cin >> n >> p >> k;
	for(int i=0; i<k ;i++) v[i]=0;
	for(int i=1; i<=n ;i++) cin >> c[i];
	cin >> x >> y;
	for(int i=1; i<=n ;i++){
		//cin >> c[i];
		if(i>=p){
			v[(i-p)%k]+=x*(49-c[i]);
		}
	}
	
	ll ans=1e18;
	ll cur=0;
	for(int i=p; i<=n ;i++){
		ans=min(ans,cur+v[(i-p)%k]);
		v[(i-p)%k]-=x*(49-c[i]);
		cur+=y;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}