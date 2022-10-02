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


#define M 100000000


int n1, n2, k1, k2;
int d[101][101][2][11];



int main() {
	cin >> n1 >> n2 >> k1 >> k2;
	d[0][0][0][0] = 1;
	int ans = 0;
	for (int i = 0; i <= n1; i++) {
		for (int j = 0; j <= n2; j++) {
			for (int g = 0; g <= k1; g++) {
				if (g != k1) {
					if (i < n1) {
						d[i + 1][j][0][g + 1] += d[i][j][0][g];
						d[i + 1][j][0][g + 1] %= M;
					}
				}
				if (j < n2) {
					d[i][j + 1][1][1] += d[i][j][0][g];
					d[i][j + 1][1][1] %= M;
				}
				if (i == n1 && j == n2) {
					ans += d[i][j][0][g];
					ans %= M;
				}
			}
			for (int g = 0; g <= k2; g++) {
				if (g != k2) {
					if (j < n2) {
						d[i][j + 1][1][g + 1] += d[i][j][1][g];
						d[i][j + 1][1][g + 1] %= M;
					}
				}
				if (i < n1) {
					d[i + 1][j][0][1] += d[i][j][1][g];
					d[i + 1][j][0][1] %= M;
				}
				if (i == n1 && j == n2) {
					ans += d[i][j][1][g];
					ans %= M;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}