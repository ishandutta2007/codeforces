#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef long long ll;
const ll mod=1e9+7;
ll n,k;
ll l;
ll bit[1000001];
void upd(ll id,ll v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]=(bit[i]+v)%mod;
}
ll qry(int id){
	ll res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res%mod;
}
pair<int,int>a[1000001];
int b[1000001];
int c[1000001];
map<int,int>mp;
bool d[1000001];
int tmp[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> l >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
		b[i]=a[i].fi;
		if(!mp[b[i]]){
			d[i]=true;
			mp[b[i]]=true;
		}
	}
	for(int i=1; i<=n ;i++){
		c[a[i].se]=i;
	}
	sort(a+1,a+n+1);
	ll ans=0;
	upd(1,1);
	ll mg=0;
	if(l>(k-1)*n){
		mg=(l-(k-1)*n)/n;
		l=(k-1)*n+l%n;
	}
	mg%=mod;
	for(int i=1; i<=k ;i++){
		for(int j=1; j<=n && ((i-1)*n+j<=l) ;j++){
			int r=lower_bound(a+1,a+n+1,make_pair(b[j]+1,0))-a-1;
			tmp[j]=qry(r);
			ans=(ans+tmp[j])%mod;
			c[j]=r;
		}
		for(int j=1; j<=n ;j++) bit[j]=0;
		for(int j=1; j<=n ;j++) upd(c[j],tmp[j]);
		upd(1,1);
	}
	for(int i=1; i<=n ;i++) bit[i]=0;
	upd(1,1);
	l=1e9;
	if(mg){
	for(int i=1; i<=k ;i++){
		if((i-1)*n>=l) break;
		for(int j=1; j<=n && ((i-1)*n+j<=l) ;j++){
			int r=lower_bound(a+1,a+n+1,make_pair(b[j]+1,0))-a-1;
			tmp[j]=qry(r);
			//ans=(ans+tmp[j])%mod;
			if(i==k) ans+=tmp[j]*mg%mod;
			ans%=mod;
		}
		for(int j=1; j<=n ;j++) bit[j]=0;
		for(int j=1; j<=n ;j++) upd(c[j],tmp[j]);
		upd(1,1);
	}
	}
	cout << ans << endl;
}