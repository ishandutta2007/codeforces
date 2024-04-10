#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set> 


using namespace std;


#define INF 1000000007


int n, k;
vector<int> v[2001];
long long dp[2001][2001];


int main(){
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				v[i].push_back(j);
			}
		}
	}
	for (int j = 1; j <= k; j++) {
		for (int i = 1; i <= n; i++) {
			if (j == 1) {
				dp[j][i] = 1;
				continue;
			}
			for (int g = 0; g < v[i].size(); g++) {
				dp[j][i] += dp[j - 1][v[i][g]];
				dp[j][i] %= INF;
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[k][i];
		ans %= INF;
	}
	cout << ans << endl;
    return 0;
}