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


#define M1 1000000007
#define M 1000000009
#define P 424243


int n;
string s;
int d[5002][5001];
int d1[5002][5001];
int h[5002];
int p[5002];


int gethash(int l, int r) {
	return (h[r] - (l > 0 ? 1LL * h[l - 1] * p[r - l + 1]: 0));
}


int main() {
	cin >> n;
	cin >> s;
	p[0] = 1;
	for (int i = 1; i <= n; i++) {
		p[i] = (1LL * p[i - 1] * P);
	}
	for (int i = 0; i < n; i++) {
		h[i] = ((i > 0 ? 1LL * h[i - 1]: 0) * P + s[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			d1[i][j] += d1[i][j - 1];
			if (d1[i][j] >= M1) {
				d1[i][j] -= M1;
			}
			int k = i - j;
			if (k < -1) {
				continue;
			}
			if (s[k + 1] == '0') {
				continue;
			}
			if (k == -1) {
				d[i][j] = 1;
				d1[i][j]++;
				if (d1[i][j] >= M1) {
					d1[i][j] -= M1;
				}
				continue;
			}
			d[i][j] += d1[k][j - 1];
			if (d[i][j] >= M1) {
				d[i][j] -= M1;
			}
			if (k + 1 >= j) {
				int ss = k - j + 1;
				int ss1 = i - j + 1;
				if (s[ss] != s[ss1]) {
					if (s[ss] < s[ss1]) {
						d[i][j] += d[k][j];
						if (d[i][j] >= M1) {
							d[i][j] -= M1;
						}
					}
				} else {
					int l = ss;
					int r = ss + j - 1;
					while (l != r) {
						int m = (l + r + 1) / 2;
						if (gethash(ss, m) != gethash(ss1, ss1 + m - ss)) {
							r = m - 1;
						} else {
							l = m;
						}
					}
					if (l != ss + j - 1) {
						if (s[l + 1] < s[ss1 + l + 1 - ss]) {
							d[i][j] += d[k][j];
							if (d[i][j] >= M1) {
								d[i][j] -= M1;
							}
						}
					}
				}
			}
			d1[i][j] += d[i][j];
			if (d1[i][j] >= M1) {
				d1[i][j] -= M1;
			}
		}
	}
	//cout << d[n - 1][n - 4] << endl;
	cout << d1[n - 1][n] << endl;
	return 0;
}