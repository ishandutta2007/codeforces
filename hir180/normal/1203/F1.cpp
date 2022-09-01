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
int n,r;
vector<P>pos,neg;
bool cmp1(const P&a,const P&b){
	return a.fi < b.fi;
}
bool cmp2(const P&a,const P&b){
	return a.fi+a.sc > b.fi+b.sc;
}
int dp[105][60005];
int main(){
	cin>>n>>r;
	if(1<=n && n<=100);else while(1);
	if(1<=r && r<=30000);else while(1);
	rep(i,n){
		int a,b; cin>>a>>b;
		if(b >= 0) pos.pb(P(a,b));
		else neg.pb(P(a,b));
		if(1<=a && a<=30000);else while(1);
		if(-300<=b && b<=300);else while(1);
	}
	
	sort(pos.begin(),pos.end(),cmp1);
	sort(neg.begin(),neg.end(),cmp2);
	rep(i,105)rep(j,60005) dp[i][j] = -INF;
	dp[0][r] = 0;
	for(int i=0;i<pos.size()+neg.size();i++){
		if(i<pos.size()){
			rep(j,60005){
				if(dp[i][j] < 0) continue;
				if(j >= pos[i].fi){
					dp[i+1][j+pos[i].sc] = max(dp[i+1][j+pos[i].sc],dp[i][j]+1);
				}
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			}
		}
		else{
			rep(j,60005){
				if(dp[i][j] < 0) continue;
				if(j >= neg[i-pos.size()].fi && j+neg[i-pos.size()].sc >= 0){
					dp[i+1][j+neg[i-pos.size()].sc] = max(dp[i+1][j+neg[i-pos.size()].sc],dp[i][j]+1);
				}
				dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
			}
		}
	}
	int ans = 0;
	rep(i,60005) ans = max(ans,dp[n][i]);
	if(ans == n){ puts("YES");}
	else puts("NO");
	return 0;
}