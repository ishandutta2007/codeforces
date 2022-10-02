#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, k;
string s;
int d[500000][26];
int c[500000][26];


int main() {
	cin >> n >> k >> s;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			int t = 0;
			if (char('A' + j) == s[i]) {
				d[i][j] = 0;
			} else {
				d[i][j] = 1;
				t = 1;
			}
			c[i][j] = -1;
			if (i > 0) {
				d[i][j] = 1000000000;
				for (int g = 0; g < k; g++) {
					if (g != j) {
						if (d[i][j] > d[i - 1][g] + t) {
							d[i][j] = d[i - 1][g] + t;
							c[i][j] = g;
						}
					}
				}
			}
		}
	}
	int ans = 1000000000;
	int x = -1;
	for (int i = 0; i < k; i++) {
		if (ans > d[n - 1][i]) {
			ans = d[n - 1][i];
			x = i;
		}
	}
	cout << ans << endl;
	string s1;
	s1.resize(n);
	int i = n - 1;
	while (i >= 0) {
		s1[i] = char(x + 'A');
		x = c[i][x];
		i--;
	}
	cout << s1 << endl;
	return 0;
}