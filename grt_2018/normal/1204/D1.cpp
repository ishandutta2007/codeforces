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

const int nax = 100*1000+10;
int n,dp[2][2],cnt,dp2[2][2];
string s,t;

int main() {_
	cin>>s;
	n=s.size();
	for(int i=n-1; i>=0; i--) {
		bool add = 0;
		dp[i&1][0] = dp[1-(i&1)][0];
		dp[i&1][1] = dp[1-(i&1)][1];
		if(s[i]=='0') {
			dp[i&1][0] = max(dp[1-(i&1)][0],dp[1-(i&1)][1])+1;
		} else {
			dp[i&1][1] = dp[1-(i&1)][1]+1;
			cnt++;
			if(dp[i&1][1]==max(dp2[1-(i&1)][0],dp2[1-(i&1)][1])+1) {
				t+='0';
				dp2[i&1][1] = dp2[1-(i&1)][1];
				dp2[i&1][0] = max(dp2[1-(i&1)][0],dp2[1-(i&1)][1])+1;
				add=1;
			}
		}
		if(!add) {
			t+=s[i];
			dp2[i&1][0] = dp[i&1][0];
			dp2[i&1][1] = dp[i&1][1];
		}
	}
	reverse(t.begin(),t.end());
	cout<<t;
}