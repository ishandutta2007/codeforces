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


int n, m;
bool good[501][501];
bool used[501];
int cntc[501];
char s[501];
 


void dfs(int i) {
	used[i] = 1;
	for (int j = 0; j < n; j++) {
		if (j != i && good[i][j]) {
			if (!used[j]) {
				s[j] = s[i];
				dfs(j);
			}
		}
	}
} 



void dfs1(int i, int c) {
	used[i] = 1;
	s[i] = 'a' + (c == 0 ? 0: 2);
	for (int j = 0; j < n; j++) {
		if (j != i && !good[i][j]) {
			if (!used[j]) {
				dfs1(j, (c + 1) % 2);
			}
		}
	}
} 



int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		good[a][b] = 1;
		cntc[a]++;
		cntc[b]++;
		good[b][a] = 1;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			s[i] = cnt + 'a';
			dfs(i);
			cnt += 2;
		}
	}
	if (cnt > 4) {
		cout << "No" << endl;
		return 0;
	}
	if (cnt == 2) {
		//cout << "opa" << endl;
		memset(used, 0, sizeof(used));
		for (int i = 0; i < n; i++) {
			if (!used[i]) {
				dfs1(i, 0);
			}
		}
		for (int i = 0; i < n; i++) {
			if (cntc[i] == n - 1) {
				s[i] = 'b';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				continue;
			}
			if (good[i][j]) {
				if (s[i] != s[j] && abs(s[i] - s[j]) != 1) {
					cout << "No" << endl;
					exit(0);
				}
			} else {
				if (s[i] == s[j] || abs(s[i] - s[j]) == 1) {
					cout << "No" << endl;
					exit(0);
				}
			}
		}
	}
	cout << "Yes" << endl;
	for (int i = 0; i < n; i++) {
		cout << s[i];
	}
	cout << endl;
	return 0;
}