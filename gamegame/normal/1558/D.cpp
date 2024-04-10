#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=4e5+1;
const ll mod=998244353;
ll n,m;
pair<int,int> a[N];
vector<int>ans;
int bit[N];
int rnk[N];
int s[N];
inline void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]+=v;
}
inline int qry(int id){
	int res=0;
	for(int i=id; i>=1 ;i-=i&-i) res+=bit[i];
	return res;
}
inline int get(int x){
	int cur=0;
	for(int i=17; i>=0 ;i--){
		if((cur+(1<<i))<=n && x>(1<<i)-bit[cur+(1<<i)]){
			cur+=1<<i;
			x-=(1<<i)-bit[cur];
		}
	}
	return cur+1;
}
ll f[N],inf[N];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
ll C(ll x,ll y){
	return f[x]*inf[y]%mod*inf[x-y]%mod;
}
ll u[N],v[N];

void solve(){
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> u[i] >> v[i];
	}
	for(int i=m; i>=1 ;i--){
		a[i].fi=get(v[i]);
		a[i].se=i;
		upd(a[i].fi,1);
	}
	for(int i=m; i>=1 ;i--){
		upd(a[i].fi,-1);
	}
	sort(a+1,a+m+1);
	int cnt=0;
	for(int i=1; i<=m ;i++){
		if(i!=m && a[i].fi+1==a[i+1].fi && a[i].se<a[i+1].se) continue;
		else if(a[i].fi==n) continue;
		else cnt++;
	}
	cnt=n-1-cnt;
	ll ans=C(cnt+n,cnt);
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	
	f[0]=1;
	int iu=400000;
	for(int i=1; i<=iu ;i++) f[i]=f[i-1]*i%mod;
	inf[iu]=pw(f[iu],mod-2);
	for(int i=iu; i>=1 ;i--) inf[i-1]=inf[i]*i%mod;
	int t;cin >> t;while(t--) solve();
}