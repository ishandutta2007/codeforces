#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>


using namespace std;


int n, k;
int c[501];
bool dp[501][501][501];



int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			for (int j1 = 0; j1 <= j; j1++) {
				if (j1 == 0 && j == 0) {
					dp[i][j][j1] = 1;
				}
				if (!dp[i][j][j1]) {
					continue;
				}
				dp[i + 1][j][j1] = max(dp[i + 1][j][j1], dp[i][j][j1]);
				if (j + c[i] <= k) {
					dp[i + 1][j + c[i]][j1] = max(dp[i + 1][j + c[i]][j1], dp[i][j][j1]);
					dp[i + 1][j + c[i]][j1 + c[i]] = max(dp[i + 1][j + c[i]][j1 + c[i]], dp[i][j][j1]);
				}
			}
		}
	}
	//cout << dp[n - 2][4][0] << endl;
	vector<int> v;
	for (int j = 0; j <= k; j++) {
		if (dp[n][k][j]) {
			v.push_back(j);
		}
	}
	cout << (int)v.size() << endl;
	for (int i = 0; i < (int)v.size(); i++) {
		printf("%d ", v[i]);
	}
	printf("\n");
	return 0;	
}