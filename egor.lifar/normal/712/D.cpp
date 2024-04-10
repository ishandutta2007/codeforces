#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;
 

 
const long long Mod = 1000000007;
long long dp[200002], sums[200002], a, b, k, t;


int main() {
	cin >> a >> b >> k >> t;
	dp[100001] = 1;
	for (int i = 1; i < 200002; i++) {
		sums[i] = sums[i - 1] + dp[i];
	}
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 200002; j++) {
			dp[j] = ((sums[min(j + k, 200001LL)] - sums[max(j - k - 1, 0LL)]) % Mod + Mod) % Mod;
		}
		for (int j = 1; j < 200002; j++) {
			sums[j] = (sums[j - 1] + dp[j]) % Mod;
		}
	}
	long long ans = 0;
	for (int j = 0; j < 200002; j++) {
		ans = ((ans + dp[j] * (sums[max(min(a + j - b - 1, 200001LL), 0LL)])) % Mod + Mod) % Mod;
	}
	cout << ans << endl;
	return 0;
}