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
#include <bitset>


using namespace std;


#define M 1000000007


int n, m;
string s[501];
int d[2][501][501];


int main() {
	cin >> n >> m;
	int l = min(n, m) + (abs(n - m)) / 2;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	if (s[0][0] != s[n - 1][m - 1]) {
		cout << 0 << endl;
		return 0;
	}
	d[0][0][0] = 1;
	//cout << l << endl;
	for (int i = 0; i < l - 1; i++) {
		for (int j = 0; j <= min(i, n - 1); j++) {
			for (int k = 0; k <= min(i, n - 1); k++) {
				int a = j;
				int b = i - j;
				int c = n - k - 1;
				int d1 = m - 1 - (i - k);
			//	cout << a << ' ' << b << ' ' << c << ' ' << d1 << endl;
				if (a + 1 < n) {
					if (c - 1 >= 0) {
						if (s[a + 1][b] == s[c - 1][d1]) {
							d[1][j + 1][k + 1] += d[0][j][k];
							d[1][j + 1][k + 1] %= M;
						}
					}
					if (d1 - 1 >= 0) {
						if (s[a + 1][b] == s[c][d1 - 1]) {
							d[1][j + 1][k] += d[0][j][k];
							d[1][j + 1][k] %= M;
						}
					}
				}
				if (b + 1 < m) {
					if (c - 1 >= 0) {
						if (s[a][b + 1] == s[c - 1][d1]) {
							d[1][j][k + 1] += d[0][j][k];
							d[1][j][k + 1] %= M;
						}
					}
					if (d1 - 1 >= 0) {
						if (s[a][b + 1] == s[c][d1 - 1]) {
							d[1][j][k] += d[0][j][k];
							d[1][j][k] %= M;
						}
					}
				}
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				d[0][j][k] = d[1][j][k];
				d[1][j][k] = 0;
			}
		}
	}	
	int ans = 0;
	if (l == 1) {
		cout << d[0][0][0] << endl;
		return 0;
	}
	int i = l - 1;
	for (int j = 0; j <= min(n - 1, i); j++) {
		for (int k = 0; k <= min(n - 1, i); k++) {
			int a = j;
			int b = i - j;
			int c = n - 1 - k;
			int d1 = m - 1 - (i - k);
		//	cout << a << ' ' << b <<  ' ' << c << ' ' << d1 << endl;
			if (abs(a - c) + abs(d1 - b) <= 1) {
				ans += d[0][j][k];
				ans %= M;
			}
		}
	}
	cout << ans << endl;
    return 0;
}