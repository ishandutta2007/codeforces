#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 200*1000+10;
const ll INF = (ll)1e18;
int t,n,a,b;
string s;
ll dp[nax][2];

int main() {_
	cin>>t;
	while(t--) {
		cin>>n>>a>>b>>s;
		dp[0][0] = b; dp[0][1]=INF;
		for(int i=1; i<=n;i++) {
			if(s[i-1]=='1') {
				dp[i][0] = INF;
				dp[i][1] = dp[i-1][1]+a+2*b;
			} else {
				dp[i][0] = min(dp[i-1][0]+b+a, dp[i-1][1]+2*a+b);
				dp[i][1] = min(dp[i-1][0]+2*a+2*b,dp[i-1][1]+a+2*b);
			}
		}
		cout<<dp[n][0]<<"\n";
	}
		
}