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
void solve(){
	cin >> n >> m >> k;
	for(int i=1; i<=k ;i++) cin >> a[i];
	for(int i=1; i<=k ;i++) cin >> b[i];
	for(int i=1; i<=n ;i++){
		c[i]=0;
	}
	for(int i=1; i<=m ;i++){
		d[i]=0;
	}
	ll ans=1LL*k*(k-1)/2;
	for(int i=1; i<=k ;i++){
		c[a[i]]++;
		d[b[i]]++;
	}
	for(int i=1; i<=n ;i++){
		ans-=c[i]*(c[i]-1)/2;
	}
	
	for(int i=1; i<=m ;i++){
		ans-=d[i]*(d[i]-1)/2;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}