#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
int n,k;
int mp,mn;
ll c[N];
ll d[N];
ll e[N];
ll f[N];
ll g[N];
ll u[N],v[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> k;k++;
	if(k==1){
		for(int i=1; i<=n ;i++) cin >> c[i];
		sort(c+1,c+n+1);
		ll ans=0;
		for(int i=1; i<=n ;i++){
			ans=ans+(i-1)*c[i];
		}
		cout << ans << '\n';
		return 0;
	}
	for(int i=1; i<=n ;i++){
		ll x;cin >> x;
		if(x<0) c[++mp]=x;
		else d[++mn]=x;
	}
	sort(c+1,c+mp+1);
	sort(d+1,d+mn+1);
	int duh=mn+(mp+k-1)/k;
	for(int i=1; i<=mp ;i++){
		e[i]=e[i-1]+((i-1)/k)*c[i];
		f[i]=f[i-1]+c[i];
		g[i]=g[i-1]+i*c[i];
	}
	for(int i=1; i<=mn ;i++){
		u[i]=u[i-1]+d[i]*i;
		v[i]=v[i-1]+d[i];
	}
	ll ans=-1e18;
	for(int i=duh; i<=n ;i++){
		ll t=(n-i)/(k-1);
		ll boss=mp-(i-mn-t);
		//cout << i << ' ' << t << ' ' << boss << endl;
		ll cur=e[t*k]+(t)*(f[boss]-f[t*k]);
		//cout << cur << endl;
		cur+=(g[mp]-g[boss])+(i-mn-mp-1)*(f[mp]-f[boss]);
		cur+=u[mn]+v[mn]*(i-mn-1);
		ans=max(ans,cur);
	}
	cout << ans << '\n';
}