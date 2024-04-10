#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSR(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n;
ll a[1000005];
vector<int>edge[1000005];
vector<pair<ll,ll> >sub_size;
int cnt[1000005],C[1000005];
ll S;
ll gcdd(ll a,ll b){
	if(a < b) swap(a,b);
	if(b == 0) return a;
	else return gcdd(b,a%b);
}
ll dfs(int v){
	ll ret = a[v];
	for(int i=0;i<edge[v].size();i++){
		ll D = dfs(edge[v][i]);
		ret += D;
		ll d = D / gcdd(D,S);
		ll s = S / gcdd(D,S);
		if(s <= n){
			sub_size.pb(mp(d,s));
			cnt[s]++;
		}
	}
	return ret;
}
bool ok[1000005];
ll dp[1000005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		S += a[i];
	}
	for(int i=2;i<=n;i++){
		int x; scanf("%d",&x);
		edge[x].pb(i);
	}
	dfs(1);
	for(int i=2;i<=n;i++){
		for(int j=1;i*j<=n;j++){
			C[i*j] += cnt[i];
		}
	}
	for(int i=0;i<sub_size.size();i++){
		if(sub_size[i].fi != 1) continue;
		if(C[sub_size[i].sc] < sub_size[i].sc-1) continue;
		assert(C[sub_size[i].sc] == sub_size[i].sc-1);
		ok[sub_size[i].sc] = 1;
	}
	ok[1] = 1;
	for(int i=n;i>=1;i--){
		if(!ok[i]) continue;
		dp[i] = 1;
		for(int j=2;i*j<=n;j++) dp[i] += dp[i*j];
		dp[i] = (dp[i]%mod+mod)%mod;
	}
	cout << dp[1] << endl;
}