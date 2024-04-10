#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define MAXN 500
#define MAXM 500

int N, M, R1, C1, R2, C2;
string grid[MAXN];
bool visited[MAXN][MAXM];

vector<pii> adj(int r, int c) {
	const int diffX[4] = {0, -1, 0, 1};
	const int diffY[4] = {1, 0, -1, 0};
	vector<pii> ret;
	for (int i = 0; i < 4; i++) {
		int r1 = r + diffX[i];
		int c1 = c + diffY[i];
		if (0 <= r1 && r1 < N && 0 <= c1 && c1 < M) {
			ret.push_back({r1, c1});
		}
	}
	return ret;
}

bool dfs(pii p) {
	// cout << p.first << ' ' << p.second << endl;
	if (visited[p.first][p.second]) {
		return false;
	}
	if (p.first == R2 && p.second == C2) {
		return true;
	}
	visited[p.first][p.second] = true;
	if (grid[p.first][p.second] == 'X' && (p.first != R1 || p.second != C1)) {
		return false;
	}
	for (pii p2 : adj(p.first, p.second)) {
		if (dfs(p2)) {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> grid[i];
	}
	cin >> R1 >> C1 >> R2 >> C2;
	R1--;C1--;R2--;C2--;

	if (R1 == R2 && C1 == C2) {
		for (pii p : adj(R1, C1)) {
			if (grid[p.first][p.second] == '.') {
				cout << "YES" << endl;
				return 0;
			}
		}
		cout << "NO" << endl;
		return 0;
	}

	if (grid[R2][C2] == '.') {
		int count = 0;
		for (pii p : adj(R2, C2)) {
			// cout << p.first << ' ' << p.second << endl;
			if (grid[p.first][p.second] == '.' || (p.first == R1 && p.second == C1)) {
				count++;
			}
		}
		if (count < 2) {
			cout << "NO" << endl;
			return 0;
		}
	}

	if (dfs({R1, C1})) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}
	return 0;
}