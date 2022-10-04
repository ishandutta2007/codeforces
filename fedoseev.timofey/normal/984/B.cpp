#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <cassert>

using namespace std;

typedef long long ll;

vector <int> dx = {-1, -1, -1, 0, 0, 1, 1, 1};
vector <int> dy = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, m;

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	cin >> n >> m;
	vector <string> f(n);
	for (int i = 0; i < n; ++i) {
		cin >> f[i];
		for (int j = 0; j < m; ++j) if (f[i][j] == '.') f[i][j] = '0';
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			char c = f[i][j];
			if ('0' <= c && c <= '8') {
				int cnt = c - '0';
				int sx = i, sy = j;
				int res = 0;
				for (int d = 0; d < 8; ++d) {
					int tx = sx + dx[d];
					int ty = sy + dy[d];
					if (ok(tx, ty)) {
						if (f[tx][ty] == '*') ++res;
					}
				}
				if (res != cnt) {
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
}