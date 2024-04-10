#include <iostream> 
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>


using namespace std;


#define M 1000000007


int r, g;
int d[2][200001];
bool b[2][200001];


int main() {
	cin >> r >> g;
	d[0][r] = 1;
	b[0][r] = true;
	int t = 0;
	for (int i = 1; i <= 893; i++) {
		int ans = 0;
		for (int j = 0; j <= r; j++) {
			int h = (i * (i + 1) / 2) - (r - j);
			if (h > g) {
				continue;
			}
			if (j + i <= r) {
				d[1][j] += d[1 - 1][j + i];
				d[1][j] %= M;
				b[1][j] = max(b[1][j], b[1 - 1][j + i]);
			}
			if (h >= i) {
				d[1][j] += d[1 - 1][j];
				d[1][j] %= M;
				b[1][j] = max(b[1][j], b[1 - 1][j]);
			}
			if (b[1][j]) {
				ans = 1;
			}
		}	
		if (!ans) {
			break;
		}
		for (int j = 0; j <= r; j++) {
			d[0][j] = d[1][j];
			b[0][j] = b[1][j];
			d[1][j] = 0;
			b[1][j] = 0;
		}
		t = max(t, ans * i);
	}
	int ans = 0;
	for (int j = 0; j <= r; j++) {
		ans += d[0][j];
		ans %= M;
	}
	cout << ans << endl;
	return 0;
}