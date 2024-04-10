#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
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
int n,s,m,k; ll a[1505];
int dp[1505][1505];
int mn[1505];
int rui[1505];
int mx[1505][1505];
int main(){
	cin>>n>>s>>m>>k; 
	repn(i,n) cin>>a[i];
	ll lb = 0, ub = 1000000005LL;
	rep(i,1505) mn[i] = INF;
	for(int i=0;i<s;i++){
		int L,R;
    	scanf("%d%d",&L,&R);
		mn[R] = min(mn[R],L);
	}
	for(int i=1;i<=n;i++){
	    if(mn[i] > 1e8) continue;
	    for(int j=i+1;j<=n;j++){
	        if(mn[i] >= mn[j]) mn[i] = INF;
	    }
	}
	while(ub-lb > 1){
		ll mid = (lb+ub)/2;
		repn(i,n) rui[i] = rui[i-1]+(a[i]<=mid);
		rep(a,1505)rep(b,1505){
			dp[a][b] = -INF;
			mx[a][b] = -INF;
		}
		dp[0][0] = 0;
		mx[0][0] = 0;
		deque<P>sld[1505];
		sld[0].push_back(mp(0,0));
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				mx[i][j] = max(mx[i][j],mx[i-1][j]);
				if(j == 0){
				    continue;
				}
				if(mn[i] != INF){
					int L = mn[i];
					while(sld[j-1].size() && sld[j-1][0].fi<L) sld[j-1].pop_front();
					dp[i][j] = max(dp[i][j],mx[L-1][j-1]+(rui[i]-rui[L-1]));
					if(sld[j-1].size()) dp[i][j] = max(dp[i][j],sld[j-1][0].sc+(rui[i]));
					mx[i][j] = max(mx[i][j],dp[i][j]);
					while(sld[j].size() && sld[j][sld[j].size()-1].sc <= dp[i][j]-rui[i]){
					    sld[j].pop_back();
					}
					sld[j].push_back(mp(i,dp[i][j]-rui[i]));
				}
			}
		}
		bool ok = 0;
		for(int j=0;j<=m;j++) if(mx[n][j] >= k) ok = 1;
		if(ok) ub = mid;
		else lb = mid;
	}
	if(ub > 1000000000) ub = -1;
	cout<<ub<<endl;
}