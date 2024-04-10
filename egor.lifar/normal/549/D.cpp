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


int n, m;
string s[1000];
int d[1000][1000];
int ans1[1000], ans2[1000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			bool b = true;
			if (i + 1 < n && s[i + 1][j] == s[i][j]) {
				b = false;
			}
			if (j + 1 < m && s[i][j + 1] == s[i][j]) {
				b = false;
			}
			if (i + 1 < n && j + 1 < m) {
				if (s[i + 1][j + 1] != s[i][j] && s[i][j + 1] == s[i][j] && s[i + 1][j] == s[i][j]) {
					b = true;
				}
				if (s[i + 1][j + 1] == s[i][j] && (s[i + 1][j] != s[i][j] || s[i][j + 1] != s[i][j])) {
					b = true;
				}
			}
			if (b) {
				ans++;
			}
		}
	}
	//cout << ans1 << endl;
	cout << ans << endl;
 	return 0;
}