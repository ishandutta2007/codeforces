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
#include <assert.h>


using namespace std;


int n, m, t;
long long c[31][31];
long long ans = 0;


int main() {
	cin >> n >> m >> t;
	for (int i = 0; i < 31; i++) {
		c[0][i] = 1;
	}
	for (int i = 1; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			c[i][j] = c[i - 1][j - 1] + c[i][j - 1];
		}
	}
	for (int i = 4; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i + j == t) {
				ans += c[i][n] * c[j][m];
			}
		}
	}
	cout << ans << endl;
    return 0;
}