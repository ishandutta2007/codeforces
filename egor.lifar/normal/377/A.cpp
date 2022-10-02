#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};


int n, m, k, s1;
string s[500];
vector<int> v[500000];
bool used[500000];
int t;
bool b = true;


void dfs(int i) {
	used[i] = true;
	if (!b) {
		s[i / 500][i % 500] = 'X';
	}
	t++;
	if (t == s1 - k) {
		b = false;
	}
	for (int j = 0; j < v[i].size(); j++) {
		int x = v[i][j];
		if (!used[x]) {
			dfs(x);
		}
	}
}


int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	int p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '.') {
				s1++;
				for (int g = 0; g < 4; g++) {
					int i1 = i + dy[g];
					int j1 = j + dx[g];
					if (i1 < 0 || j1 < 0 || i1 >= n || j1 >= m) {
						continue;
					}
					if (s[i1][j1] != '.') {
						continue;
					}
					v[i * 500 + j].push_back(i1 * 500 + j1);
				}
				p = i * 500 + j;
			}
		}
	}
	dfs(p);
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
	return 0;
}