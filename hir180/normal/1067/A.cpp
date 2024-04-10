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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int dp[100005][205][2];
int up[100005][205];
int dw[100005][205];
int a[100005],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=200;i++){
		if(a[1] == -1 || a[1] == i){
			dp[1][i][0] = 1;
		}
	}
	for(int i=1;i<=200;i++){
		up[1][i] = up[1][i-1]+dp[1][i][0]+dp[1][i][1];
	}
	for(int i=200;i>=1;i--){
		dw[1][i] = dw[1][i+1]+dp[1][i][1];
	}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=200;j++){
			if(a[i] != -1 && a[i] != j) continue;
			dp[i][j][0] = up[i-1][j-1];
			dp[i][j][1] = up[i-1][j]-up[i-1][j-1]+dw[i-1][j+1];
			dp[i][j][1] = (dp[i][j][1]%mod+mod)%mod;
		}
		for(int j=1;j<=200;j++){
			up[i][j] = up[i][j-1]+dp[i][j][0];
			up[i][j] %= mod;
			up[i][j] = up[i][j]+dp[i][j][1];
			up[i][j] %= mod;
		}
		for(int j=200;j>=1;j--){
			dw[i][j] = dw[i][j+1]+dp[i][j][1];
			dw[i][j] %= mod;
		}
	}
	ll ans = 0;
	for(int i=1;i<=200;i++) ans += dp[n][i][1];
	cout<<(ans%mod+mod)%mod<<endl;
}