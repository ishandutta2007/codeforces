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
int n,m,a[100005];
int dp[100005],dp2[100005],val[100005];
int main(){
	cin>>n>>m;
	repn(i,n){
		int x,y;cin>>x>>y;
		a[x]++; a[y+1]--;
	}
	repn(i,m) a[i] += a[i-1];
	rep(i,100005)val[i]=INF;
	val[0] = 0;
	repn(i,m){
		int x = upper_bound(val,val+100005,a[i])-val;
		val[x] = min(val[x],a[i]);
		dp[i] = x;
	}
	rep(i,100005)val[i]=INF;
	val[0] = 0;
	for(int i=m;i>=1;i--){
		int x = upper_bound(val,val+100005,a[i])-val;
		val[x] = min(val[x],a[i]);
		dp2[i] = x;
	}
	int ans = 0;
	repn(i,m) ans=max(ans,dp[i]+dp2[i]-1);
	cout<<ans<<endl;
}