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
double sum[65][65][65],dp[65][65][65];
int n; double a[65][65];
void calc(int L,int R,int d){
	if(L == R) return;
	int x = L+R; x/=2;
	calc(L,x,d/2);
	calc(x+1,R,d/2);
	for(int i=L;i<=x;i++){
		for(int j=x+1;j<=R;j++){
			//dp[L][x][i],dp[x+1][R][j]
			dp[L][R][i] += dp[L][x][i]*dp[x+1][R][j]*a[i][j];
			dp[L][R][j] += dp[L][x][i]*dp[x+1][R][j]*a[j][i];
			sum[L][R][i] = max(sum[L][R][i],sum[L][x][i]+sum[x+1][R][j]);
			sum[L][R][j] = max(sum[L][R][j],sum[L][x][i]+sum[x+1][R][j]);
		}
	}
	for(int i=L;i<=R;i++) sum[L][R][i] += (double)d * dp[L][R][i];
}
int main(){
	cin>>n; n = 1<<n;
	repn(i,n){
		repn(j,n){
			cin>>a[i][j];
			a[i][j] /= 100.0;
		}
	}
	for(int i=1;i<=n;i++){
		sum[i][i][i] = 0.0;
		dp[i][i][i] = 1.0;
	}
	calc(1,n,n/2); double ret=0;
	for(int i=1;i<=n;i++) ret=max(ret,sum[1][n][i]);
	printf("%.12f\n",ret);
}