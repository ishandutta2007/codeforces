#include <sstream>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <set>


using namespace std;


int n;
long long a[2001][2001];
int xx, yy, x1, y11;
int x, y;
long long ans, ans1;
long long d[4001], d1[4001];
int b[2000][2000];
int c[2000][2000];



int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%I64d", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		x = n - i - 1;
		y = 0;
		while (x < n && y < n) {
			c[x][y] = i;
			d[i] += a[x][y];
			x++;
			y++;
		}
	}
	for (int i = 1; i < n; i++) {
		x = 0;
		y = i;
		while (x < n && y < n) {
			c[x][y] = i + n - 1;
			d[i + n - 1] += a[x][y];
			x++;
			y++;
		}
	}

	for (int i = 0; i < n; i++) {
		x = 0;
		y = i;
		while (x < n && y >= 0) {
			b[x][y] = i;
			d1[i] += a[x][y];
			x++;
			y--;
		}
	}
	for (int i = 1; i < n; i++) {
		x = i;
		y = n - 1;
		while (x < n && y >= 0) {
			b[x][y] = i + n - 1;
			d1[i + n - 1] += a[x][y];
			x++;
			y--;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if ((i + j) % 2 == 0) {
				if (ans <= d[c[i][j]] + d1[b[i][j]] - a[i][j]) {
					ans = d[c[i][j]] + d1[b[i][j]] - a[i][j];
					xx = i + 1;
					yy = j + 1;
				}
			} else {
				if (ans1 <= d[c[i][j]] + d1[b[i][j]] - a[i][j]) {
					ans1 = d[c[i][j]] + d1[b[i][j]] - a[i][j];
					x1 = i + 1;
					y11 = j + 1;
				}
			}
		}
	}
	cout << ans + ans1 << endl;
	cout << xx << ' ' << yy << ' ' << x1 << ' ' << y11 << endl;
	return 0;
}