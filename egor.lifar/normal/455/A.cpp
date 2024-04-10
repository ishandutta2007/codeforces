#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
long long a[100000];
long long c[100001];
long long dp[100001];
long long k = 0;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		c[a[i]]++;
		k = max(k, a[i]);
	}
	dp[1] = c[1];
	for (int i = 2; i <= k; i++) {
		dp[i] = max(dp[i - 2] + i * c[i], dp[i - 1]);
	}
	cout << dp[k] << endl;
	return 0;
}