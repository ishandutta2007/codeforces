#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <cmath>
#include <cassert>


using namespace std;


int n, m;
bool used[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
string s[1001];


void dfs(int i, int j) {
	used[i][j] = 1;
	for (int k = 0; k < 4; k++) {
		int ni = i + dx[k];
		int nj = j + dy[k];
		if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
			continue;
		} 
		if (s[ni][nj] == '.') {
			continue;
		}
		if (!used[ni][nj]) {
			dfs(ni, nj);
		}
	}
}


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!used[i][j]) {
				if (s[i][j] != '.') {
					dfs(i, j);
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
 	return 0;
}