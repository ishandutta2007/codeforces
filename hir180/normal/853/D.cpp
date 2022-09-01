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
int n;
ll dp[300005][105],a[300005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=0;i<300005;i++)for(int j=0;j<105;j++) dp[i][j]=1e18;
	dp[0][0] = 0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<105;j++){
			if(dp[i-1][j] > 1e17) continue;
			//all buy
			if(j+a[i]/1000 < 105){
				dp[i][j+a[i]/1000] = min(dp[i][j+a[i]/1000],dp[i-1][j]+a[i]);
			}
			//use all bonus
			int need = a[i]/100;
			dp[i][j-min(j,need)] = min(dp[i][j-min(j,need)],dp[i-1][j]+a[i]-min(j,need)*100);
		}
	}
	ll ans = 1e18;
	for(int j=0;j<105;j++) ans=min(ans,dp[n][j]);
	cout<<ans<<endl;
}