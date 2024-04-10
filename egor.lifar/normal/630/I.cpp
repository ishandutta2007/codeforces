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
#include <vector>
#include <bitset>


using namespace std;


unsigned long long d[70][70][6][3];


int main() {
	int n;
	cin >> n;
	d[0][0][0][0] = 1;
	for (int i = 0; i < 2 * n - 2; i++) {
		for (int j = 0; j <= i + 1; j++) {
			for (int k = 0; k <= 4; k++) {
				for (int g = 0; g <= 1; g++) {
					for (int h = 1; h <= 4; h++) {
						int j1 = 0;
						if (h == k) {
							j1 = j + 1;
						} else {
							j1 = 1;
						}
						int g1 = g;
						if ((j == n && j1 == 1) || (j1 == n && i == 2 * n - 3)) {
							g1 = 1;
						}
						d[i + 1][j1][h][g1] += d[i][j][k][g];
					}
				}
			} 
		}
	}
	unsigned long long sum = 0;
	for (int j = 1; j <= 2 * n - 2; j++) {
		for (int k = 1; k <= 4; k++) {
			//cout << d[2 * n - 2][j][k][1] << ' ' << k << ' ' << j << endl;
			sum += d[2 * n - 2][j][k][1];
		}
	}
	cout << sum << endl;
	return 0;
}
//1 1 3
//1 3 1
//3 1 1
//1 2 2