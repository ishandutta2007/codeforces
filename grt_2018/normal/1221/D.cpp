#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using pi = pair<int,int>;
#define ST first
#define ND second
#define PB push_back
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int nax = 300*1000+10;
const ll INF=1e18;
ll dp[2][3];
int n,q;
int h[nax];
int c[nax];

int main() {_
	cin>>q;
	while(q--) {
		cin>>n;
		for(int i=1; i<=n; i++) {
			cin>>h[i]>>c[i];
		}
		for(int i=0; i<2; i++) for(int j=0; j<3; j++) dp[i][j] = 0;
		dp[1][1] = c[1]; dp[1][2] = 2*c[1];
		for(int i=2; i<=n; i++) {
			for(int j=0; j<3; j++) {
				dp[i%2][j] = INF;
				for(int k=0; k<3; k++) {
					if(h[i-1]+k!=h[i]+j) dp[i%2][j] = min(dp[i%2][j],dp[1-(i%2)][k]);
				}
				dp[i%2][j]+=c[i]*j;
				//cout<<dp[i%2][j]<<" ";
			}
			//cout<<"\n";
		}
		cout<<min({dp[n%2][0],dp[n%2][1],dp[n%2][2]})<<"\n";
	}
					
}