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
int n,a[5005];
int dp[5005][5005][3];
int main(){
	cin>>n;
	repn(i,n){
		cin>>a[i];
	}
	rep(a,5005)rep(b,5005)rep(c,3) dp[a][b][c] = INF;
	dp[0][0][2] = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<=i;j++){
			dp[i+1][j][1] = min(dp[i+1][j][1],dp[i][j][0]);
			dp[i+1][j+1][0] = min(dp[i+1][j+1][0],dp[i][j][1]+max(0,a[i]-min((i?a[i-1]:0),a[i+1])+1));
			dp[i+1][j][2] = min(dp[i+1][j][2],dp[i][j][1]+max(0,a[i]-(i?a[i-1]:0)+1));
			dp[i+1][j][2] = min(dp[i+1][j][2],dp[i][j][2]);
			dp[i+1][j+1][0] = min(dp[i+1][j+1][0],dp[i][j][2]+max(0,a[i]-(a[i+1])+1));
		}
	}
	for(int i=1;i<=(n+1)/2;i++) printf("%d ",min(dp[n][i][0],min(dp[n][i][1]+max(0,a[n]-a[n-1]+1),dp[n][i][2])));
	puts("");
}