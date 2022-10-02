#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>


using namespace std;


int n, m;
string s[100000];
int a[100][100000], b[100][100000];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		int k = -2;
		int l = m - 1;
		while(s[i][l] != '1' && l >= 0) {
			l--;
		}
		if (l == -1) {
			cout << -1 << endl;
			return 0;
		}
		for (int j = 0; j < m; j++) {
			a[i][j] = m - l + j;
			if (a[i][j] < 0) {
				a[i][j] = 1000000000;
			}
		}
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') {
				k = j;
			}
			if (k >= 0) {
				a[i][j] = min(a[i][j], j - k);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		int k = -2;
		int l = 0;
		while(s[i][l] != '1' && l < m) {
			l++;
		}
		if (l == m) {
			cout << -1 << endl;
			return 0;
		}
		for (int j = m - 1; j >= 0; j--) {
			b[i][j] = l + m - j;
			if (b[i][j] < 0) {
				b[i][j] = 1000000000;
			}
		}
		for (int j = m - 1; j >= 0; j--) {
			if (s[i][j] == '1') {
				k = j;
			}
			if (k >= 0) {
				b[i][j] = min(b[i][j], k - j);
			}
		}
	}
	long long ans = 1000000000;
	for (int i = 0; i < m; i++) {
		long long s = 0;
		for (int j = 0; j < n; j++) {
			s += min(a[j][i], b[j][i]);
		}
		ans = min(ans, s);
	}
	cout << ans << endl;
	return 0;
}