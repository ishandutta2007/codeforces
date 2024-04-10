#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

const int N = 288;
int dp[N][N][N];

void remin(int& x, int y) {
	if (x == -1 || (x > y && y > -1)) {
		x = y;
	}
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), q = nxt();
	string s;
	cin >> s;
	vector<array<int, 26>> nc(n + 1);
	nc[n].fill(-1);
	for (int i = n - 1; i >= 0; --i) {
		nc[i] = nc[i + 1];
		nc[i][s[i] - 'a'] = i + 1;
	}

	string r[3] = {"", "", ""};
	dp[0][0][0] = 0;
	for (int i = 0; i < q; ++i) {
		char op;
		int idx;
		cin >> op >> idx;
		idx -= 1;
		if (op == '+') {
			char c;
			cin >> c;
			r[idx] += c;
			int ids[3] = {-1, -1, -1};
			ids[idx] = r[idx].size();
			int id1 = (idx + 1) % 3;
			int id2 = (idx + 2) % 3;
			for (ids[id1] = 0; ids[id1] <= (int)r[id1].size(); ++ids[id1]) {
				for (ids[id2] = 0; ids[id2] <= (int)r[id2].size(); ++ids[id2]) {
					dp[ids[0]][ids[1]][ids[2]] = -1;
					for (int j = 0; j < 3; ++j) {
						if (ids[j] > 0 && dp[ids[0] - (j == 0)][ids[1] - (j == 1)][ids[2] - (j == 2)] > -1) {
							remin(dp[ids[0]][ids[1]][ids[2]], nc[dp[ids[0] - (j == 0)][ids[1] - (j == 1)][ids[2] - (j == 2)]][r[j][ids[j] - 1] - 'a']);
						}
					}
				}
			}
			// ids[idx] -= 1;
			// for (ids[id1] = 0; ids[id1] <= (int)r[id1].size(); ++ids[id1]) {
			// 	for (ids[id2] = 0; ids[id2] <= (int)r[id2].size(); ++ids[id2]) {
			// 		if (dp[ids[0]][ids[1]][ids[2]] > -1) {
			// 			remin(dp[ids[0] + (idx == 0)][ids[1] + (idx == 1)][ids[2] + (idx == 2)], nc[dp[ids[0]][ids[1]][ids[2]]][c - 'a']);
			// 		}
			// 	}
			// }
		} else {
			r[idx].pop_back();
		}

		cout << (dp[r[0].size()][r[1].size()][r[2].size()] > -1 ? "YES" : "NO") << "\n";
	}

	return 0;
}