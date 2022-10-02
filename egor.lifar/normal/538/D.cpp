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
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
string s[100000];
bool b[100][100];
map<pair<int, int>, bool> m;
char ans[100][100];


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == '.') {
				for (int i1 = 0; i1 < n; i1++) {
					for (int j1 = 0; j1 < n; j1++) {
						if (s[i1][j1] == 'o') {
							m[make_pair(i - i1, j - j1)] = true;
							//cout << i - i1 << ' ' << j - j1 << endl;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] != 'o') {
				continue;
			}
			for (int i1 = 0; i1 <= 2 * n; i1++) {
				for (int j1 = 0; j1 <= 2 * n; j1++) {
					if (m[make_pair(i1 - n, j1 - n)]) {
						continue;
					}
					int i2 = i1 - n;
					int j2 = j1 - n;
					if (i + i2 >= 0 && i + i2 < n && j + j2 < n && j + j2 >= 0) {
						b[i + i2][j + j2] = true;
						// if (i + i2 == 1 && j + j2 == 1) {
						// 	cout << i << ' ' << j << endl;
						// }
						//cout << i + i2 << ' ' << j + j2 << endl;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i][j] == 'x' && !b[i][j]) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
		for (int i1 = 0; i1 < 2 * n; i1++) {
			for (int j1 = 0; j1 < 2 * n; j1++) {
			if (m[make_pair(i1 - n + 1, j1 - n + 1)]) {
				continue;
			}
			int i2 = i1 - n + 1;
			int j2 = j1 - n + 1;
			ans[n - 1 + i2][n - 1 + j2] = 'x';
		}
	}
	ans[n - 1][n - 1] = 'o';
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < 2 * n - 1; j++) {
			if (ans[i][j] != 'o' && ans[i][j] != 'x') {
				cout << '.';
			} else {
				cout << ans[i][j];
			}
		}
		cout << endl;
	}
    return 0;	
}