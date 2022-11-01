#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(char c) {
	if (c <= '9') return c - '0';
	return c - 'A' + 10;
}

int gcd(int a, int b) {
	if (a % b) return gcd(b, a % b);
	return b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector <vector <int>> a(n, vector <int> (n));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < (n >> 2); j++) {
			char c;
			cin >> c;
			int x = f(c);
			a[i][(j << 2)] = ((x & 8) != 0);
			a[i][(j << 2) + 1] = ((x & 4) != 0);
			a[i][(j << 2) + 2] = ((x & 2) != 0);
			a[i][(j << 2) + 3] = ((x & 1) != 0);
		}
	int ans = n;
	for (int i = 0; i < n; i++) {
		int curlen = 0;
		for (int j = 0; j < n; j++) {
			if (j && a[i][j] != a[i][j - 1]) {
				ans = gcd(ans, curlen);
				curlen = 0;
			}
			curlen++;
		}
	}
	for (int j = 0; j < n; j++) {
		int curlen = 0;
		for (int i = 0; i < n; i++) {
			if (i && a[i][j] != a[i - 1][j]) {
				ans = gcd(ans, curlen);
				curlen = 0;
			}
			curlen++;
		}
	}
	cout << ans;
	return 0;
}