#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
ll mx;
ll a[1000005],b[1000005];
ll dp[2][(1<<11)][12];
vector<P>tp[1000005];
vector<int>mask[1000005];
ll g;
ll gcdd(ll a,ll b){
	if(a<b) swap(a,b);
	if(b == 0) return a;
	else return gcdd(b,a%b);
}
vector<ll>za;
ll trans[1000005];
vector<ll>pr;
ll x[(1<<12)] = {};
ll val[(1<<12)];
int main(){
	scanf("%d%lld",&n,&mx);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		g = gcdd(g,a[i]);
	}
	if(g == 1){puts("0"); return 0;}
	for(int i=1;i<=n;i++){
		scanf("%lld",&b[i]);
	}
	for(ll i=2;i*i<=g;i++){
		if(g%i == 0){
			pr.pb(i);
			while(g%i==0) g/=i;
		}
	}
	if(g > 1) pr.pb(g);
	for(int i=1;i<=n;i++){
		trans[i] = 1;
		ll A = a[i];
		for(int j=0;j<pr.size();j++){
			while(A%pr[j] == 0){
				A /= pr[j];
				
			}
		}
		trans[i] = a[i]/A;
		za.pb(trans[i]);
	}
	SORT(za); ERASE(za);
	for(int i=1;i<=n;i++){
		int x = POSL(za,trans[i]);
		tp[x].pb(mp(b[i],i));
	}
	for(int i=0;i<za.size();i++) SORT(tp[i]);
	int sz = pr.size();
	for(int i=0;i<za.size();i++){
		while(tp[i].size() > 11) tp[i].pop_back();
		if(tp[i].empty()) continue;
		
		int M = tp[i][0].sc;
		x[0] = 1;
		for(int ii=0;ii<sz;ii++){
			ll V = 1, gen = a[M];
			while(gen%pr[ii] == 0){
				gen /= pr[ii];
			}
			val[(1<<ii)] = a[M]/gen;
		}
		for(int ii=1;ii<(1<<sz);ii++){
			int w = (ii & (-ii));
			x[ii] = x[ii-w] * val[w];
		}
		rep(j,tp[i].size()){
			int M = tp[i][j].sc;
			for(int ii=0;ii<(1<<sz);ii++){
				if(x[ii] <= mx){
					mask[M].pb(ii);
				}
			}
		}
	}
	rep(a,(1<<sz)) rep(b,sz+1) dp[0][a][b] = dp[1][a][b] = 1e18;
	dp[0][0][0] = 0;
	int cur = 0,nxt = 1;
	repn(i,n){
	    if(mask[i].empty()) continue;
	    //memcpy(dp[cur],dp[nxt],sizeof(dp[cur]));
	    rep(a,(1<<sz)) rep(b,sz+1) dp[nxt][a][b] = dp[cur][a][b];
		for(int j=0;j<mask[i].size();j++){
			int go = mask[i][j];
			int beg = (1<<sz)-1-go;
			int bs = beg;
			while(1){
				rep(j,sz) dp[nxt][beg+go][j+1] = min(dp[nxt][beg+go][j+1],dp[cur][beg][j]+b[i]);
				if(beg == 0) break;
				beg = (beg-1) & bs;
			}
		}
		swap(cur,nxt);
	}
	ll ans = 1e18;
	repn(x,sz) if(dp[cur][(1<<sz)-1][x]<1e17) ans = min(ans,dp[cur][(1<<sz)-1][x]*1LL*x);
	if(ans > 1e17) ans = -1;
	cout<<ans<<endl;
}