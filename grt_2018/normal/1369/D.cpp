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

const int nax = 2000*1000+10, mod = 1e9 + 7;
ll t, dp[nax];

int main() {_
	cin >> t;
	dp[3] = 1;
	for(int i = 4; i <= 2000*1000; ++i) {
		dp[i] = (ll)dp[i-1] + 2LL*dp[i-2] + (i%3 ==0 ? 1 : 0);
		dp[i] %= mod;
	}
	while(t--) {
		int x;
		cin >> x;
		cout << (4LL*dp[x])%mod << "\n";
	}
	
			
	
}