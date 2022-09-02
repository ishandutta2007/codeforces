#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<P,int> P1;
typedef pair<P,P> P2;
typedef pair<double,int>Q;
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
typedef complex<double> pt;
int n,dp[55][2],a[55],sum;
int rec(int nxt,int ply){
	if(nxt == n+1) return 0;
	if(dp[nxt][ply]>=0) return dp[nxt][ply];
	if(ply == 0){
		return dp[nxt][ply] = max(rec(nxt+1,ply),rec(nxt+1,1-ply)+a[nxt]);
	}
	else{
		return dp[nxt][ply] = min(rec(nxt+1,ply)+a[nxt],rec(nxt+1,1-ply));
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; sum+=a[i];
	}
	memset(dp,-1,sizeof(dp));
	int b = rec(1,1);
	cout<<b<<" "<<sum-b<<endl;
}