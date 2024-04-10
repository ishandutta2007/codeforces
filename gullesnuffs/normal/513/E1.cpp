#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define rrep(i, a, b) for(int i = (a) - 1; i >= int(b); --i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)
#define all(v) (v).begin(), (v).end()
#define what_is(x) cerr << #x << " is " << x << endl;

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;

int dp[405][55][2];
int dpSum[405][55][2];
int a[405];
int sum[405];

bool better0(int val1, int sum1, int val2, int sum2){
	if(sum2-sum1 > val2-val1 || 
		(sum2-sum1 == val2-val1 && sum2 > sum1))
		return 1;
	return 0;
}
bool better1(int val1, int sum1, int val2, int sum2){
	if(sum1-sum2 > val2-val1 || 
		(sum1-sum2 == val2-val1 && sum2 < sum1))
		return 1;
	return 0;
}

int main(){
	int n, K;
	scanf("%d%d", &n, &K);
	rep(i,0,n){
		scanf("%d", a+i);
		sum[i+1]=sum[i]+a[i];
	}
	rep(i,1,K+1)
		rep(j,0,n+1){
			dp[j][i][0]=-1000000000;
			dp[j][i][1]=-1000000000;
		}
	int ans=0;
	rep(i,1,K+2){
		rep(j,0,n)
			rep(k,j+1,n+1){
				ans=max(ans,dp[k][K][0]);
				ans=max(ans,dp[k][K][1]);
				if(better0(dp[k-1][i-1][0],dpSum[k-1][i-1][0],dp[k][i-1][0],dpSum[k][i-1][0])){
					dp[k][i][0]=dp[k][i-1][0];
					dpSum[k][i][0]=dpSum[k][i-1][0];
				}
				if(better1(dp[k-1][i-1][1],dpSum[k-1][i-1][1],dp[k][i-1][1],dpSum[k][i-1][1])){
					dp[k][i][1]=dp[k][i-1][1];
					dpSum[k][i][1]=dpSum[k][i-1][1];
				}
				int s=sum[k]-sum[j];
				int val=0;
				if(i == 1)
					val=0;
				else{
					val=max(dp[j][i-1][0]+abs(dpSum[j][i-1][0]-s),dp[j][i-1][1]+abs(dpSum[j][i-1][1]-s));
				}
				if(better0(val,s,dp[k][i][0],dpSum[k][i][0])){
					dp[k][i][0]=val;
					dpSum[k][i][0]=s;
				}
				if(better1(val,s,dp[k][i][1],dpSum[k][i][1])){
					dp[k][i][1]=val;
					dpSum[k][i][1]=s;
				}
			}
	}
	printf("%d\n", ans);
}