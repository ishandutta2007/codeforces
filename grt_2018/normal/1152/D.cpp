#include <bits/stdc++.h>

using namespace std;

using LL = long long;
using vi = vector<int>;
using pii = pair<int,int>;
#define ST first
#define ND second
#define PB push_back

const int nax= 2001;
const int mod=1000*1000*1000+7;
int n;
int dp[nax][nax][2];

int main() {
	scanf("%d",&n);
	for(int i=2*n-1; i>=0;i--) {
		for(int b=0; b<=n;b++) {
			int opt1=0,opt2=0;
			if(b>0) {
				dp[i][b][0] = max(dp[i+1][b-1][0],dp[i+1][b-1][1]);
				opt1 = (dp[i+1][b-1][0]+1)%mod;
				if(2*n-i>b) {
					opt1=(max(dp[i+1][b+1][0],dp[i+1][b+1][1])+opt1)%mod;
				}
			}
			if(2*n-i>b) {
				dp[i][b][0] = (dp[i][b][0]+max(dp[i+1][b+1][0],
					dp[i+1][b+1][1]))%mod;
				opt2 = (dp[i+1][b+1][0]+1)%mod;
				if(b>0) {
					opt2 = (opt2+max(dp[i+1][b-1][0],dp[i+1][b-1][1]))%mod;
				}
			}
			dp[i][b][1] = max(opt1,opt2);
		}
	}
	printf("%d",max(dp[0][0][1],dp[0][0][0]));
}