#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <unordered_set>


using namespace std;


#define INF 1000000000;


int v1, v2;
int t;
int d;
int dp[100][2000];


int main() {
	cin >> v1 >> v2;
	cin >> t >> d;
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j <= 1999; j++) {
			dp[i][j] = -INF;
		}
	}
	dp[0][v1] = 0;
	for (int i = 1; i < t; i++) {
		for (int j = 0; j <= 1999; j++) {
			for (int k = max(0, j - d); k <= min(1999, j + d); k++) {
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + k);
			}
		}
	}
	cout << dp[t - 1][v2] + v2 << endl;
    return 0;
}