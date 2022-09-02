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
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,a[2005];
int cnt[2005],cnt2[2005];
int main(){
	cin>>n;
	repn(i,n) cin>>a[i];
	repn(i,n){
		cnt[i] = cnt[i-1]+(a[i]==1);
	}
	for(int i=n;i>=1;i--){
		cnt2[i] = cnt2[i+1]+(a[i]==2);
	}
	int ans = 0;
	repn(j,n){
		int dp[3]={};
		dp[0] = 0;
		dp[1] = dp[2] = -INF;
		for(int i=j;i>=1;i--){
			if(a[i]==1){
				dp[1]=max(dp[1],dp[0])+1;
			}
			else{
				dp[2]=max(dp[2],max(dp[1],dp[0]))+1;
			}
			ans = max(ans,cnt[i-1]+cnt2[j+1]+max(0,max(dp[1],dp[2])));
		}
	}
	cout<<ans<<endl;
}