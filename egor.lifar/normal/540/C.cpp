#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int n, m;
string s[100000];
bool used[3000][3000];


void dfs(int i, int j) {
	used[i][j] = true;
	for (int g = 0; g < 4; g++) {
		int i1 = i + dx[g];
		int j1 = j + dy[g];
		if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
			continue;
		}
		if (s[i1][j1] == '.' && !used[i1][j1]) {
			dfs(i1, j1);
		}
	}	
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int r1, c1;
	cin >> r1 >> c1;
	int r2, c2;
	cin >> r2 >> c2;
	r1--;c1--;r2--;c2--;
	if (r1 == r2 && c2 == c1) {
		int k = 0;
		for (int g = 0; g < 4; g++) {
			int i = r1 + dx[g];
			int j = c1 + dy[g];
			if (i < 0 || j < 0 || i >= n || j >= m) {
				continue;
			}
			if (s[i][j] == '.') {
				k++;
			}
		}
	//	cout << k << endl;
		if (k) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
		return 0;
	}
	s[r1][c1] = '.';
	char c = s[r2][c2];
	s[r2][c2] = '.';
	dfs(r1, c1);
	//cout << used[r2][c2];
	if (used[r2][c2]) {
		if (c == 'X') {
			cout << "YES" << endl;
			return 0;
		}
		s[r1][c1] = '.';
		int k = 0;
		for (int g = 0; g < 4; g++) {
			int i = r2 + dx[g];
			int j = c2 + dy[g];
			if (i < 0 || j < 0 || i >= n || j >= m) {
				continue;
			}
			if (s[i][j] == '.') {
				k++;
			}
		}
		if (k >= 2) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
    return 0;
}