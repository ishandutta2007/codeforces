#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<unordered_map>
#include<queue>
#include<stack>
#include<string>
#include<bitset>
#include<random>
#include<complex>
#include<time.h>
#define MOD 1000000007ll
#define INF 1000000000ll
#define EPS 1e-7
#define REP(i,m) for(long long i=0; i<(ll)m; i++)
#define FOR(i,n,m) for(long long i=n; i<(ll)m; i++)
#define DUMP(a) for(long long dump=0; dump<(ll)a.size(); dump++) { cout<<a[dump]; if(dump!=(ll)a.size()-1) cout<<" "; else cout<<endl; }
#define ALL(v) v.begin(),v.end()
#define UNIQUE(v) sort(v.begin(),v.end()); v.erase(unique(v.begin(),v.end()),v.end());
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	vector<string> buf(2);
	cin>>buf[0]>>buf[1];
	ll n=buf[0].size();
	vector<vector<ll>> g(2,vector<ll>(n));
	REP(i,2) REP(j,n) {
		if(buf[i][j]=='0') g[i][j]=0;
		else g[i][j]=1;
	}
	vector<vector<ll>> dp(n,vector<ll>(4,-1));
	if(g[0][0]==0&&g[1][0]==0) dp[0][0]=0;
	if(g[0][0]==0&&g[1][0]==1) dp[0][1]=0;
	if(g[0][0]==1&&g[1][0]==0) dp[0][2]=0;
	if(g[0][0]==1&&g[1][0]==1) dp[0][3]=0;
	FOR(i,1,n) {
		if(g[0][i]==0&&g[1][i]==0) dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
		if(g[0][i]==0&&g[1][i]==1) dp[i][1]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
		if(g[0][i]==1&&g[1][i]==0) dp[i][2]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
		if(g[0][i]==1&&g[1][i]==1) dp[i][3]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
		if(dp[i-1][0]!=-1) {
			if(g[0][i]==0&&g[1][i]==0) {
				dp[i][1]=max(dp[i][1],dp[i-1][0]+1);
				dp[i][2]=max(dp[i][2],dp[i-1][0]+1);
			}
			if(g[0][i]==0&&g[1][i]==1) dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
			if(g[0][i]==1&&g[1][i]==0) dp[i][3]=max(dp[i][3],dp[i-1][0]+1);
		}
		if(dp[i-1][1]!=-1) {
			if(g[0][i]==0&&g[1][i]==0) {
				dp[i][3]=max(dp[i][3],dp[i-1][1]+1);
			}
		}
		if(dp[i-1][2]!=-1) {
			if(g[0][i]==0&&g[1][i]==0) {
				dp[i][3]=max(dp[i][3],dp[i-1][2]+1);
			}
		}
	}
	cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2],dp[n-1][3]})<<endl;
}