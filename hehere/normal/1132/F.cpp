#include <bits/stdc++.h>
using namespace std;

const int maxN = 500 + 5;
int n;
char s[maxN];
int p[maxN], f[maxN][maxN];

void chmin(int &x, int y) {
	if(y < x) x = y;
}

int main() {
	cin >> n;
	cin >> (s + 1);
	for(int i = 1; i <= n; ++i)
		for(int j = i - 1; j <= n; ++j)
				f[i][j] = j - i + 1;
	for(int len = 2; len <= n; ++len)
		for(int i = 1, j = i + len - 1; j <= n; ++i, ++j) {
			chmin(f[i][j], f[i + 1][j] + 1);
			chmin(f[i][j], f[i][j - 1] + 1);
			if(s[i] == s[j]) chmin(f[i][j], f[i + 1][j - 1] + 1);
//			for(int k = i + 1, last = i, sum = 0; k <= j; ++k) {
//				if(s[k] == s[last]) {
//					sum += f[last + 1][k - 1];
//					chmin(f[i][j], 1 + sum + f[k + 1][j]);
//					last = k;
//				}
//			}
			for(int k = i; k < j; ++k)
				chmin(f[i][j], f[i][k] + f[k + 1][j]);
			for(int k = i + 1; k < j; ++k)
				chmin(f[i][j], f[i][k] + f[k][j] - 1);
		}
	cout << f[1][n] << endl;
	return 0;
}