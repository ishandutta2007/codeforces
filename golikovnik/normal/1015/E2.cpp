#include <bits/stdc++.h>

#define int long long
#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())

using namespace std;

struct Star {
	int x, y, d;
};

const int N = 1111;
int up[N][N], down[N][N], left_[N][N], right_[N][N];
int sumx[N][N], sumy[N][N];

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10); cout << fixed;
	int n, m;
	cin >> n >> m;
	vector<vector<char>> star(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c;
			cin >> c;
			star[i][j] = (c == '*');
			up[i][j] = down[i][j] = left_[i][j] = right_[i][j] = star[i][j];
		}
	}
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j < m; ++j) {
			if (star[i][j]) {
				up[i][j] = up[i - 1][j] + 1;
				left_[i][j] = left_[i][j - 1] + 1;
			}
		}
	}
	for (int i = n - 2; i >= 0; --i) {
		for (int j = m - 2; j >= 0; --j) {
			if (star[i][j]) {
				down[i][j] = down[i + 1][j] + 1;
				right_[i][j] = right_[i][j + 1] + 1;
			}
		}
	}
	vector<Star> ans;
	for (int i = 1; i + 1 < n; ++i) {
		for (int j = 1; j + 1 < m; ++j) {
			if (star[i][j]) {
				int cango = min(min(
					up[i][j], down[i][j]), min(left_[i][j], right_[i][j])) - 1;
				if (cango <= 0) continue;
				ans.push_back({i, j, cango});
				++sumx[i][j - cango];
				--sumx[i][j + cango + 1];
				++sumy[i - cango][j];
				--sumy[i + cango + 1][j];
			}
		}
	}
	vector<vector<char>> ok(n, vector<char>(m));
	for (int i = 0; i < n; ++i) {
		int cnt = 0;
		for (int j = 0; j < m; ++j) {
			cnt += sumx[i][j];
			if (star[i][j] && cnt > 0) {
				ok[i][j] = 1;
			}
		}
	}
	for (int j = 0; j < m; ++j) {
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cnt += sumy[i][j];
			if (star[i][j] && !ok[i][j] && cnt <= 0) {
				puts("-1");
				return 0;
			}
		}
	}
	cout << szof(ans) << "\n";
	for (Star &s: ans) {
		cout << s.x + 1 << " " << s.y + 1 << " " << s.d << "\n";
	}
	return 0;	
}