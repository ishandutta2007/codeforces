#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,k;
ll a[N],b[N],c[N];
bool f[N];
void solve(){
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		c[a[i]]=i;
		f[i]=false;
	}
	for(int i=1; i<=k ;i++){
		cin >> b[i];
		b[i]=c[b[i]];
		f[b[i]]=true;
	}
	f[0]=f[n+1]=true;
	ll ans=1;
	for(int i=1; i<=k ;i++){
		ll x=0;
		x+=!f[b[i]-1];
		x+=!f[b[i]+1];
		ans=ans*x%mod;
		f[b[i]]=false;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}