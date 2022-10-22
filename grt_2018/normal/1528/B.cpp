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

// x - - - - - x | y - - - - - y | z - - - - - z num of divisors
// x y z - - - - - - x y z
// x - - - - - - - - - - x
// f(n) = f(n - 2) + length = k 
// inside all 
// intersect

const int nax = 1e6 + 10, mod = 998244353;
int n;
int dp[nax], dp2[nax], cnt[nax];
 

int main() {_
	cin >> n;
	dp[0] = dp2[0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			cnt[j]++;
		}
	}
	for(int i = 1; i <= n; ++i) {
		//~ for(int j = 2; j < 2 * i; j += 2) {
			//~ if((2 * i) % j == 0) {
				//~ dp[i] = (dp[i] + 1) % mod;
			//~ }
		//~ }
		dp[i] = cnt[i] - 1;
		dp[i] = (dp[i] + dp2[i - 1]) % mod;
		dp2[i] = (dp2[i - 1] + dp[i]) % mod;
	}
	cout << dp[n];
	
	
}