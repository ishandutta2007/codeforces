#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n;
pair<ll,int> a[N];
int b[N];
ll bit1[N];
ll bit2[N];
void upd(ll* bit,int id,ll v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]=(bit[i]+v)%mod;
}
ll qry(ll* bit,int id){
	ll res=0;
	for(int i=id; i>=1 ;i-=i&-i) res=(res+bit[i])%mod;
	return res;
}
ll dp[N];
ll s[N],w[N];
ll g[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=-i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++){
		a[i].se=-a[i].se;
		int x=a[i].se;
		b[x]=i;
		ll ways=(1+qry(bit2,x))%mod;
		ll sum=(qry(bit1,x)+ways)%mod;
		upd(bit1,x,sum);
		upd(bit2,x,ways);
		s[x]=sum,w[x]=ways;
		//cout << x << ' ' << s[x] << ' ' << w[x] << endl;
	}
	ll ans=0;
	for(int i=1; i<=n ;i++){
		bit1[i]=bit2[i]=0;
		ans=(ans+s[i])%mod;
	}
	int mx=0;
	for(int i=n; i>=1 ;i--){
		if(mx>b[i]) continue;
		g[i]=1;upd(bit1,i,1);
		
		for(int j=b[i]-1; j>mx ;j--){
			int x=a[j].se;
			ll duh=qry(bit1,n)-qry(bit1,x);
			g[x]=duh;
			upd(bit1,x,duh);
		}
		for(int j=b[i]; j>mx ;j--){
			int x=a[j].se;
			ans=(ans-w[x]*g[x])%mod;
			if(ans<0) ans+=mod;
			upd(bit1,x,mod-g[x]);
		}
		mx=b[i];
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--) solve();
}