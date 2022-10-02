#include <cstdio>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n, k;
bool b[1000][1000];



int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m;
		cin >> m;
		int x;
		int l = -1, r = -1;
		int s1 = 0;
		for (int j = 0; j < k; j++) {
			for (int g = 0; g <= k - m; g++) {
				bool t = true;
				int s = 0;
				for (int h = g; h <= g + m - 1; h++) {
					if (b[j][h]) {
						t = false;
					}
					s += abs(k / 2 - j) + abs(k / 2 - h);
				}
				if (t) {
					if (l == -1) {
						l = g;
						r = g + m - 1;
						x = j;
						s1 = s; 
					} else {
						if (s < s1) {
							l = g;
							r = g + m - 1;
							x = j;
							s1 = s; 
						}
					}
				}
			}
		}
		if (l != -1) {
			cout << x + 1 << ' ' << l + 1 << ' ' << r + 1 << endl;
			for (int j = l; j <= r; j++) {
				b[x][j] = true;
			}
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}