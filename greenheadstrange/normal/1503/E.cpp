//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 4105 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x, T y) {return x < y ? x = y, true : false;}
template <typename T> bool chkmin(T &x, T y) {return x > y ? x = y, true : false;}

using namespace std;

int n, m;
int c[maxn][maxn];
int ans;
int main() {
	scanf("%d%d", &n, &m);
	c[0][0] = 1;
	for (int i = 1; i <= n + m; i++) {
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j < i; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % mod;
		}
	}
	auto walk = [&](int p, int q, int r, int s) {
		int x = abs(p - r), y = abs(q - s);
		return (ll)c[x + y][x];
	};
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			ans = (ans + walk(0, 0, i, j - 1) * walk(i - 1, j, 0, m) % mod * walk(i, j + 1, n, m) % mod * walk(i + 1, j, n, 0)) % mod;
		}
	}
	auto solve = [&](int n, int m) {
		for (int i = 1; i < n; i++) {
			int fs = 0;
			for (int j = 1; j < m; j++) {
				ans = (ans +  fs * walk(i + 1, j, n, 0) % mod * walk(i, j + 1, n, m)) % mod;
				fs = (fs + walk(0, 0, i, j - 1) * walk(i - 1, j, 0, m)) % mod;
			}
		}
	};
	solve(n, m);
	solve(m, n);
	ans = (ans * 2) % mod;
	printf("%d\n", ans);
}