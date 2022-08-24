#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline long long nxt() {
	long long x;
	scanf("%lld", &x);
	return x;
}

#define fixed kdrjasdgls

char a[8][8];
char fixed[8][8];
int k;

pair<int, int> fromCell(string s) {
	return {s[1] - '1', s[0] - 'a'};
}

string toCell(int x, int y) {
	return string(1, 'a' + y) + string(1, '1' + x);
}

const int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool isok(int x, int y) {
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

char used[8][8];
pair<int, int> pr[8][8];

int main() {
	cin >> k;
	for (int i = 0; i < k; ++i) {
		string s;
		cin >> s;
		auto p = fromCell(s);
		a[p.first][p.second] = 1;
	}

	bool rev = k > 32;
	if (rev) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 0; j < 8; ++j) {
				swap(a[i][j], a[7 - i][7 - j]);
			}
		}
		for (int i = 0; i < 8; ++i) {
			for (int j = 0; j < 8; ++j) {
				a[i][j] ^= 1;
			}
		}
		k = 64 - k;
	}

	vector<array<int, 4>> ans;
	for (int i = 0; i < k; ++i) {
		int x = i / 8, y = i % 8;
		if (a[x][y]) {
			fixed[x][y] = 1;
			continue;
		}

		queue<pair<int, int>> st;
		st.push({x, y});
		memset(used, 0, sizeof(used));
		int tx = -1, ty = -1;
		while (!st.empty()) {
			auto v = st.front();
			st.pop();
			for (int d = 0; d < 8; ++d) {
				int nx = v.first + dx[d];
				int ny = v.second + dy[d];

				if (!isok(nx, ny) || used[nx][ny] || fixed[nx][ny]) {
					continue;
				}
				used[nx][ny] = 1;
				pr[nx][ny] = v;
				st.push({nx, ny});
				if (a[nx][ny]) {
					tx = nx;
					ty = ny;
					break;
				}
			}
			if (tx > -1) {
				break;
			}
		}
		assert(tx > -1);

		a[tx][ty] = 0;
		while (tx != x || ty != y) {
			ans.push_back({tx, ty, pr[tx][ty].first, pr[tx][ty].second});
			auto v = pr[tx][ty];
			tx = v.first;
			ty = v.second;
		}
		a[x][y] = 1;

		fixed[x][y] = 1;
	}

	if (rev) {
		for (auto& v : ans) {
			v = {7 - v[2], 7 - v[3], 7 - v[0], 7 - v[1]};
		}
	}
	cout << ans.size() << "\n";
	for (auto v : ans) {
		cout << toCell(v[0], v[1]) << "-" << toCell(v[2], v[3]) << "\n";
	}

	return 0;
}