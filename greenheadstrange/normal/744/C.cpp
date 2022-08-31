#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int dp[1 << 16][600];
int n;
int tp[maxn], r[2][maxn];
int main() {
	cin >> n;
	int u[2] = {0, 0};
	for (int i = 0; i < n; i++) {
		char inp[3];
		scanf("%s", inp);;
		if (inp[0] == 'R') tp[i] = 0;
		else tp[i] = 1;
		scanf("%d%d", &r[0][i], &r[1][i]);
		for (int j = 0; j < 2; j++)
			if (r[j][i] > n)
				u[j] += r[j][i] - n, 
				r[j][i] = n;
	} 
	int pls = n * n;
	for (int i = (1 << n) - 1; i >= 0; i--) {
		int c[2] = {0, 0};
		for (int j = 0; j < n; j++)
			if (i & (1 << j)) c[tp[j]]++;
		for (int j = pls - n * (c[0] + c[1]); j <= n * (c[0] + c[1]) + pls; j++) {
			int v = j - pls;
			if (i == (1 << n) - 1) 
				dp[i][j] = max(u[0], u[1] + v);
			else {
				dp[i][j] = 2e9;
				for (int q = 0; q < n; q++) {
					if (i & (1 << q)) continue;
					int ed = i ^ (1 << q);
					int u1 = max(0, r[0][q] - c[0]), v1 = max(0, r[1][q] - c[1]);
					int nans = u1 + dp[ed][j + v1 - u1];
					if (nans < dp[i][j]) dp[i][j] = nans;
				}
			}
	//		cout << i << ' ' << j << ' ' << dp[i][j] << endl;
		}
	}
	cout << dp[0][pls] + n << endl;
	return 0;
}
/*
5 4
0 1 2 3

*/