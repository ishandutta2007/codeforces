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


int n, m;
string s[10000];
bool b[5000][5000];


int main() {
	cin >> n;
	m = n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!b[i][j]) {
				if (s[i][j] == '#') {
					if (j == 0 || j == m - 1 || i >= n - 2) {
						cout << "NO" << endl;
						return 0;
					}
					if (s[i + 1][j] != '#' || s[i + 2][j] != '#' || s[i + 1][j - 1] != '#' || s[i + 1][j + 1] != '#') {
						cout << "NO" << endl;
						return 0;
					}
					if (b[i + 1][j] || b[i + 2][j] || b[i + 1][j - 1] || b[i + 1][j + 1]) {
						cout << "NO" << endl;
						return 0;
					}
					b[i + 1][j - 1] = true;
					b[i + 1][j + 1] = true;
					b[i + 1][j] = true;
					b[i + 2][j] = true;
				}
			}
		}
	}
	cout << "YES" << endl;
    return 0;
}