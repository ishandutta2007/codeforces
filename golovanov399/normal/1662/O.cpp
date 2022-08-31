#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int A = 22;
const int B = 360;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

bool wall[A][B][4];
bool used[A][B];

bool dfs(int x, int y) {
	if (x < 0) {
		return false;
	}
	if (used[x][y]) {
		return false;
	}
	if (x == A - 1) {
		return true;
	}
	used[x][y] = true;
	for (int i = 0; i < 4; ++i) {
		if (!wall[x][y][i] && dfs(x + dx[i], (y + dy[i] + B) % B)) {
			return true;
		}
	}
	return false;
}

void solve() {
	memset(wall, 0, sizeof(wall));
	int n = nxt();
	while (n--) {
		char type;
		cin >> type;
		if (type == 'C') {
			int r = nxt();
			int phi1 = nxt(), phi2 = nxt();
			for (int i = phi1; i != phi2; i = (i + 1) % B) {
				wall[r - 1][i][2] = 1;
				wall[r][i][0] = 1;
			}
		} else {
			int r1 = nxt(), r2 = nxt();
			int phi = nxt();
			for (int i = r1; i < r2; ++i) {
				wall[i][(phi + B - 1) % B][1] = 1;
				wall[i][phi][3] = 1;
			}
		}
	}

	memset(used, 0, sizeof(used));
	if (dfs(0, 0)) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}