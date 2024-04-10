#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
const ll mod = 1000000007;

int n;
ll a[1000005],sum;
vector<ll>pr;
pair<ll,ll>nw[5];
int main(){
	scanf("%d",&n);
	repn(i,n){
		scanf("%lld",&a[i]); 
		sum += a[i];
	}
	if(sum == 1){
		puts("-1");
		return 0;
	}
	for(ll i=2;i*i<=sum;i++){
		if(sum%i != 0) continue;
		pr.pb(i);
		while(sum%i == 0) sum /= i;
	}
	if(sum != 1) pr.pb(sum);
	ll ans = 1e18;

	rep(i,pr.size()){
		vector<pair<ll,ll>>dp;
		dp.pb(mp(0,0));
		repn(ii,n){
			ll rem = a[ii] % pr[i];
			ll plus = pr[i]-rem;
			int nxt = 0;
			rep(j,dp.size()){
				nw[nxt++] = (mp(dp[j].fi-rem,abs(dp[j].fi-rem)+dp[j].sc));
				nw[nxt++] = (mp(dp[j].fi+plus,abs(dp[j].fi+plus)+dp[j].sc));
			}
			sort(nw,nw+nxt);
			dp.clear();
			ll pre = -1e18;
			rep(j,nxt){
				if(abs(nw[j].fi) >= pr[i]) continue;
				if(pre == nw[j].fi) continue;
				pre = nw[j].fi;
				dp.pb(nw[j]);
			}
		}
		rep(i,dp.size()){
			if(dp[i].fi == 0) ans = min(ans,dp[i].sc);
		}
	}
	cout << ans << endl;
}