#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int M=2e5+1;
const int N=5e6+1;
ll n,m;
ll p[M],k[M];
ll seed,base;
ll rnd(){
	ll ret=seed;
	seed=(seed*base+233)%mod;
	return ret;
}
ll a[N],t[N];
ll cnt[3];
ll ans[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> p[i] >> k[i] >> seed >> base;
		for(int j=p[i-1]+1; j<=p[i] ;j++){
			t[j]=rnd()%2+1;
			a[j]=rnd()%k[i]+1;
			cnt[t[j]]+=a[j];
		}
	}
	if(cnt[1]<cnt[2]){
		for(int j=1; j<=n ;j++) t[j]=3-t[j];
	}
	if(t[1]==1){
		a[1]--;ans[1]++;
	}
	ll suf=0;
	for(int i=1; i<=n ;i++){
		if(t[i]==1) suf=min(0LL,suf+a[i]);
		else suf=min(0LL,suf-a[i]);
	}
	
	ll res=1;
	for(int i=1; i<=n ;i++){
		if(t[i]==2) ans[i]+=a[i];
		else ans[i]+=min(a[i],-suf);
		if(t[i]==1) suf=min(0LL,suf+a[i]);
		else suf=min(0LL,suf-a[i]);
		//cout << suf << ' ' << ans[i] << endl;
		res=res*((ans[i]^(1LL*i*i))%mod+1)%mod;
	}
	cout << res << '\n';
}