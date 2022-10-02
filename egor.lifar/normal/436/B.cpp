#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>


using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
char c[4] = {'U', 'D', 'L', 'R'};


int n, m, k;
string s[100000];

 
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < m; i++) {
		int ans = 0;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < 4; k++) {
				int j1 = j + dy[k] * j;
				int i1 = i + dx[k] * j;
				if (i1 < 0 || j1 < 0 || i1 >= m || j1 >= n) {
					continue;
				}
				if (s[j1][i1] == c[k]) {
					ans++;
				}
				//cout << s[j1][i1] << ' ' << c[k] << ' ' << j + 1 << ' ' << i + 1 << endl;
			}
		}
		cout << ans << ' ';
	}
	cout << endl;
	return 0;
}