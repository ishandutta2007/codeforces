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
#include <queue>


using namespace std;


int n, m;
string a[1001];
int b[1001][1001];


int main() {
	cin >> n;
	m = n;
	int posx = n, posy = n;
	int pos1x = -1, pos1y = -1;
	for (int i = n - 1; i >= 0; i--) {
		cin >> a[i];
		for (int j = 0; j < m; j++) {
			if (a[i][j] != '0') {
				if (i < posx) {
					posx = i;
					posy = j;
				} else {
					if (i == posx && j < posy) {
						posx = i;
						posy = j;
					}
				}
				if (i > pos1x) {
					pos1x = i;
					pos1y = j;
				} else {
					if (i == pos1x && j > pos1y) {
						pos1x = i;
						pos1y = j;
					}
				}
			}
		}
	}
	pos1x--;
	pos1y--;
	if (posx >= pos1x || posy >= pos1y) {
		cout << "No" << endl;
		return 0;
	}
	for (int i = posx + 1; i <= pos1x; i++) {
		b[i][posy] = 2;
		b[i][pos1y + 1] = 2;
	}
	for (int i = posy + 1; i <= pos1y; i++) {
		b[posx][i] = 2;
		b[pos1x + 1][i] = 2;
	}
	b[posx][posy] = 1;
	b[pos1x + 1][pos1y + 1] = 1;
	b[posx][pos1y + 1] = 1;
	b[pos1x + 1][posy] = 1;
	if (pos1x - posx == 1 && pos1y - posy == 1) {
		b[pos1x][pos1y] = 4;
	} else {
		if (pos1x - posx == 1) {
			for (int j = posy + 1; j <= pos1y; j++) {
				b[pos1x][j] = 4;
			}
		} else {
			if (pos1y - posy == 1) { 
				for (int j = posx + 1; j <= pos1x; j++) {
					b[j][pos1y] = 4;
				}
			} else {
				for (int i = posx + 1; i <= pos1x; i++) {
					for (int j = posy + 1; j <= pos1y; j++) {
						b[i][j] = 4;
					}
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] - '0' != b[i][j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}