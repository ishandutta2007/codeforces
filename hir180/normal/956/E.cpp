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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[2][10005][2],n,l,r;
P p[10005];
bool cmp(const P&a,const P&b){
	if(a.sc != b.sc) return a.sc < b.sc;
	else return a.fi > b.fi;
}
int main(){
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++) cin>>p[i].fi;
	for(int i=1;i<=n;i++) cin>>p[i].sc;
	sort(p+1,p+n+1,cmp);
	rep(a,2)rep(b,10005)rep(c,2)dp[a][b][c]=-INF;
	dp[0][0][0] = 0;
	int cur = 0,nxt = 1;
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<10005;j++) rep(k,2) dp[nxt][j][k] = -INF;
		for(int j=0;j<=r;j++){
		    rep(k,2){
    			if(dp[cur][j][k] < 0) continue;
    			dp[nxt][j][(k|p[i].sc)] = max(dp[nxt][j][(k|p[i].sc)],dp[cur][j][k]);
    			if(j+p[i].fi<=r){
    			    int add = (p[i].sc==1 && l<=j && j<=r);
    				dp[nxt][j+p[i].fi][k] = max(dp[nxt][j+p[i].fi][k],dp[cur][j][k]+add);
    			}
		    }
		}
		swap(cur,nxt);
		for(int j=0;j<=r;j++){
		    if(j>=l){
    		    ans=max(ans,dp[cur][j][1]+1);
    		    ans=max(ans,dp[cur][j][0]+(i!=n&&p[n].sc==1));
		    }
		    else{
		        ans=max(ans,dp[cur][j][1]);
    		    ans=max(ans,dp[cur][j][0]);
		    }
		}
	}
	cout<<ans<<endl;
}