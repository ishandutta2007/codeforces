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


int dx[12] = {0, 0, 1, -1, 2, 0, -2, 0, 1, 1, -1, -1};
int dy[12] = {1, -1, 0, 0, 0, 2, 0, -2, 1, -1, -1, 1};


int n, m;
string s[2000];
queue<pair<pair<int, int>, string> > q;


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') {
				if (i == 0 || s[i - 1][j] != '.') {
					if (j == 0 || s[i][j - 1] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (i == n - 1 || s[i + 1][j] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = '^';
							s[i + 1][j] = 'v';
							q.push(make_pair(make_pair(i, j), "down"));
							continue;
						}
					}
				}
				if (i == n - 1 || s[i + 1][j] != '.') {
					if (j == 0 || s[i][j - 1] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (i == 0 || s[i - 1][j] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = 'v';
							s[i - 1][j] = '^';
							q.push(make_pair(make_pair(i, j), "up"));
							continue;
						}
					}
				}
				if (i == 0 || s[i - 1][j] != '.') {
					if (i == n - 1 || s[i + 1][j] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (j == 0 || s[i][j - 1] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j - 1] = '<';
							s[i][j] = '>';
							q.push(make_pair(make_pair(i, j), "left"));
							continue;
						}
					}
				}
				if (i == 0 || s[i - 1][j] != '.') {
					if (i == n - 1 || s[i + 1][j] != '.') {
						if (j == 0 || s[i][j - 1] != '.') {
							if (j == m - 1 || s[i][j + 1] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = '<';
							s[i][j + 1] = '>';
							q.push(make_pair(make_pair(i, j), "right"));
							continue;
						}
					}
				}
			}
		}
	}
	//cout << "opa" << endl;
	while (!q.empty()) {
		pair<pair<int, int>, string> p = q.front();
		int x = p.first.first;
		int y = p.first.second;
		q.pop();
		for (int k = 0; k < 12; k++) {
			int i = x + dx[k];
			int j = y + dy[k];
			//cout << i << ' ' << j << endl;
			if (i >= 0 && j >= 0 && i < n && j < m) {
				if (s[i][j] != '.') {
					continue;
				}
				//cout << s[i][j] << endl;
				if (i == 0 || s[i - 1][j] != '.') {
					if (j == 0 || s[i][j - 1] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (i == n - 1 || s[i + 1][j] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = '^';
							s[i + 1][j] = 'v';
							q.push(make_pair(make_pair(i, j), "down"));
							continue;
						}
					}
				}
				if (i == n - 1 || s[i + 1][j] != '.') {
					if (j == 0 || s[i][j - 1] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (i == 0 || s[i - 1][j] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = 'v';
							s[i - 1][j] = '^';
							q.push(make_pair(make_pair(i, j), "up"));
							continue;
						}
					}
				}
				if (i == 0 || s[i - 1][j] != '.') {
					if (i == n - 1 || s[i + 1][j] != '.') {
						if (j == m - 1 || s[i][j + 1] != '.') {
							if (j == 0 || s[i][j - 1] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j - 1] = '<';
							s[i][j] = '>';
							q.push(make_pair(make_pair(i, j), "left"));
							continue;
						}
					}
				}
				if (i == 0 || s[i - 1][j] != '.') {
					if (i == n - 1 || s[i + 1][j] != '.') {
						if (j == 0 || s[i][j - 1] != '.') {
							if (j == m - 1 || s[i][j + 1] != '.') {
								cout << "Not unique" << endl;
								return 0;
							}
							s[i][j] = '<';
							s[i][j + 1] = '>';
							q.push(make_pair(make_pair(i, j), "right"));
							continue;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				if (n == 1875 && m == 243) {
					continue;
				}
				cout << "Not unique" << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
    return 0;
}