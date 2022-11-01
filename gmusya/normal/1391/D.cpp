#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	bool tf = false;
	if (n > m) {
		swap(n, m);
		tf = true;
	}
	vector <vector <int>> arr(n, vector <int>(m));
	if (!tf) 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				char c;
				cin >> c;
				arr[i][j] = c - '0';
			}
	else
		for (int j = 0; j < m; j++)
			for (int i = 0; i < n; i++) {
				char c;
				cin >> c;
				arr[i][j] = c - '0';
			}
	if (n > 3) {
		cout << -1;
		return 0;
	}
	if (n == 1) {
		cout << 0;
		return 0;
	}
	if (n == 3) {
		vector <vector <vector <int>>> sq;
		for (int mask = 0; mask < (1 << 9); mask++) {
			vector <vector <int>> a(3, vector <int>(3));
			for (int i = 0; i < 9; i++)
				if ((1 << i) & (mask))
					a[i / 3][i % 3] = 1;
			bool tf = true;
			for (int x = 0; x < 2; x++)
				for (int y = 0; y < 2; y++) {
					int s = a[x][y] + a[x + 1][y] + a[x][y + 1] + a[x + 1][y + 1];
					if (s % 2 == 0) tf = false;
				}
			if (tf) sq.push_back(a);
		}
		vector <vector <int>> g(sq.size());
		for (int i = 0; i < sq.size(); i++)
			for (int j = 0; j < sq.size(); j++) {
				bool tf = true;
				for (int x = 0; x < 3; x++)
					for (int y = 0; y < 2; y++)
						if (sq[i][x][y + 1] != sq[j][x][y])
							tf = false;
				if (tf)
					g[i].push_back(j);
			}
		vector <vector <int>> dp(m - 2, vector <int>(sq.size(), INF));
		for (int s = 0; s < sq.size(); s++) {
			int sum = 0;
			for (int i = 0; i < 3; i++)
				for (int j = 0; j < 3; j++)
					sum += (sq[s][i][j] != arr[i][j]);
			dp[0][s] = sum;
		}
		for (int pos = 0; pos < m - 3; pos++)
			for (int olds = 0; olds < sq.size(); olds++)
				for (int news : g[olds]) {
					int s = 0;
					for (int i = 0; i < 3; i++)
						s += (sq[news][i][2] != arr[i][pos + 3]);
					dp[pos + 1][news] = min(dp[pos + 1][news], dp[pos][olds] + s);
				}
		int mi = INF;
		for (int i = 0; i < sq.size(); i++) 
			mi = min(dp[m - 3][i], mi);
		cout << mi;
		return 0;
	}
	if (n == 2) {
		vector <vector <vector <int>>> sq;
		for (int mask = 0; mask < (1 << 4); mask++) {
			vector <vector <int>> a(2, vector <int>(2));
			for (int i = 0; i < 4; i++)
				if ((1 << i) & (mask))
					a[i / 2][i % 2] = 1;
			bool tf = true;
			int s = a[0][0] + a[1][0] + a[0][1] + a[1][1];
			if (s % 2 == 0) tf = false;
			if (tf) sq.push_back(a);
		}
		vector <vector <int>> g(sq.size());
		for (int i = 0; i < sq.size(); i++)
			for (int j = 0; j < sq.size(); j++) {
				bool tf = true;
				for (int x = 0; x < 2; x++)
					for (int y = 0; y < 1; y++)
						if (sq[i][x][y + 1] != sq[j][x][y])
							tf = false;
				if (tf)
					g[i].push_back(j);
			}
		vector <vector <int>> dp(m - 1, vector <int>(sq.size(), INF));
		for (int s = 0; s < sq.size(); s++) {
			int sum = 0;
			for (int i = 0; i < 2; i++)
				for (int j = 0; j < 2; j++)
					sum += (sq[s][i][j] != arr[i][j]);
			dp[0][s] = sum;
		}
		for (int pos = 0; pos < m - 2; pos++)
			for (int olds = 0; olds < sq.size(); olds++)
				for (int news : g[olds]) {
					int s = 0;
					for (int i = 0; i < 2; i++)
						s += (sq[news][i][1] != arr[i][pos + 2]);
					dp[pos + 1][news] = min(dp[pos + 1][news], dp[pos][olds] + s);
				}
		int mi = INF;
		for (int i = 0; i < sq.size(); i++) 
			mi = min(dp[m - 2][i], mi);
		cout << mi;
		return 0;
	}
	return 0;
}