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


using namespace std;


int n, m;
string s[2000];
queue<pair<int, int> > q;
int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, -1, 1};


void bfs() {
	while (!q.empty()) {
		pair<int, int> p = q.front();
		q.pop();
		for (int g = 0; g < 8; g++) {
			int i = p.first + dy[g];
			int j = p.second + dx[g];
			if (i < 0 || j < 0 || i >= n || j >= m) {
				continue;
			}
			if (s[i][j] == '*') {
				if (i > 0 && j > 0) {
					if (s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i - 1][j - 1] == '.') {
						s[i][j] = '.';;
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i > 0 && j < m - 1) {
					if (s[i - 1][j] == '.' && s[i][j + 1] == '.' && s[i - 1][j + 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i < n - 1 && j > 0) {
					if (s[i + 1][j] == '.' && s[i][j - 1] == '.' && s[i + 1][j - 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i < n - 1 && j < m - 1) {
					if (s[i + 1][j] == '.' && s[i][j + 1] == '.' && s[i + 1][j + 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
			}

		}
	}
}


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '*') {
				if (i > 0 && j > 0) {
					if (s[i - 1][j] == '.' && s[i][j - 1] == '.' && s[i - 1][j - 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i > 0 && j < m - 1) {
					if (s[i - 1][j] == '.' && s[i][j + 1] == '.' && s[i - 1][j + 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i < n - 1 && j > 0) {
					if (s[i + 1][j] == '.' && s[i][j - 1] == '.' && s[i + 1][j - 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
				if (i < n - 1 && j < m - 1) {
					if (s[i + 1][j] == '.' && s[i][j + 1] == '.' && s[i + 1][j + 1] == '.') {
						s[i][j] = '.';
						q.push(make_pair(i, j));
						continue;
					}
				}
			}
		}
	}
//	cout << (int)q.size() << endl;
	bfs();
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
	return 0;
}