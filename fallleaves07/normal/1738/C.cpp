#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	int codd = 0, ceven = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] = (a[i] % 2 == 0) ? 0 : 1;
		if (a[i]) {
			++codd;
		} else {
			++ceven;
		}
	}
	vector f(codd + 1, vector(ceven + 1, vector<int>(2)));
	f[0][0][0] = true;
	for (int i = 0; i <= codd; i++) {
		for (int j = 0; j <= ceven; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			for (int k = 0; k < 2; k++) {
				int step = ((codd + ceven - i - j) & 1);
				if (step == 0) {
					f[i][j][k] = false;
					if (i > 0 && f[i - 1][j][k ^ 1]) {
						f[i][j][k] = true;
					}
					if (j > 0 && f[i][j - 1][k]) {
						f[i][j][k] = true;
					}
				} else {
					f[i][j][k] = true;
					if (i > 0 && !f[i - 1][j][k]) {
						f[i][j][k] = false;
					}
					if (j > 0 && !f[i][j - 1][k]) {
						f[i][j][k] = false;
					}
				}
			}
		}
	}
	if (f[codd][ceven][0]) {
		puts("Alice");
	} else {
		puts("Bob");
	}
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}