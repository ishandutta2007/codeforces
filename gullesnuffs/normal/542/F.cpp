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

int t[1005], q[1005];
int dp[1005][1005];
vector<int> val[105];

int main(){
	int n, T;
	scanf("%d%d", &n, &T);
	rep(i,0,n){
		scanf("%d%d", t+i, q+i);
		val[T-t[i]].push_back(q[i]);
	}
	rep(i,0,1005)
	rep(j,0,1005)
		dp[i][j]=-1000000000;
	int ans=0;
	rep(i,0,T+1){
		rep(j,0,n+1){
			dp[i+1][min(2*j,n)]=max(dp[i+1][min(2*j,n)],dp[i][j]);
		}
		dp[i+1][1]=max(dp[i+1][1], 0);
		rep(k,0,val[i].size()){
			int cur=val[i][k];
			rep(j,1,n+1){
				dp[i+1][j-1]=max(dp[i+1][j-1],dp[i+1][j]+cur);
				ans=max(ans, dp[i+1][j-1]);
			}
		}
	}
	printf("%d\n", ans);
}