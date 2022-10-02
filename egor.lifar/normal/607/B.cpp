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


int n;
int a[520];
int d[520][520];
bool b[520][520];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (i == j) {
				b[i][j] = 1;
				continue;
			}
			if (i - j == -1) {
				if (a[i] == a[j]) {
					b[i][j] = 1;
				} else {
					b[i][j] = 0;
				}
				continue;
			} 
			b[i][j] = ((a[i] == a[j]) & (j > 0 ? b[i + 1][j - 1]: 1));
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (j - i <= 1 && a[j] == a[i]) {
				d[i][j] = 1;
				continue;
			}
			if (j - i == 1 && a[j] != a[i]) {
				d[i][j] = 2;
				continue;
			}
			d[i][j] = j - i + 1;
			d[i][j] = min(d[i][j], 1 + d[i + 1][j]);
			d[i][j] = min(d[i][j], 1 + d[i][j - 1]);
			d[i][j] = min(d[i][j], 2 + d[i + 1][j - 1]);
			if (a[i] == a[j]) {
				d[i][j] = min(d[i][j], d[i + 1][j - 1]);
			}
			for (int g = i + 1; g < j; g++) {
				d[i][j] = min(d[i][j], d[i][g] + d[g + 1][j]);
			}
		}
	}
	cout << d[0][n - 1] << endl;
	return 0;
}