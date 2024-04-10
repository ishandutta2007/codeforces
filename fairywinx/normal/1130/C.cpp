// #define GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <assert.h>
#include <iomanip>
#include <deque>
#include <map>
// #include <cmath>
#include <bitset>

// #include <algorithm>
#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif
	srand(time(0));
}

const int N = 55;

int A[N][N];
bool used[N][N];
int col[N][N];
vector<pair<int, int>> G[N][N];

int mx[4] = {0, 0, -1, 1};
int my[4] = {1, -1, 0, 0};

void dfs(pair<int, int> v, vector<pair<int, int>> &comp, int color) {
	comp.push_back(v);
	used[v.first][v.second] = 1;
	col[v.first][v.second] = color;
	for(auto i: G[v.first][v.second]) {
		if (!used[i.first][i.second])
			dfs(i, comp, color);
	}
}

signed main() {
	setup();
	// SOLVE;
	int n;
	cin >> n;
	pair<int, int> s, f;
	cin >> s.first >> s.second >> f.first >> f.second;
	--s.first, --s.second, --f.first, --f.second;
	vector<vector<pair<int, int>>> comp;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			char c;
			cin >> c;
			A[i][j] = c - '0';
		}
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			for(int k = 0; k < 4; ++k) {

				int x = i + mx[k], y = j + my[k];
				if (x >= 0 && x < n && y >= 0 && y < n) {
					if (A[i][j] == 0 && A[x][y] == 0)
						G[i][j].push_back(make_pair(x, y));
				}

			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if (!used[i][j] && A[i][j] == 0) {
				comp.push_back(vector<pair<int, int>> ());
				dfs({i, j}, comp.back(), comp.size() - 1);
			}
		}
	}

	int ans = 1e9;
	int c1 = col[s.first][s.second], c2 = col[f.first][f.second];
	for(auto i: comp[c1]) {
		for(auto j: comp[c2])
			ans = min(ans, (i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second));
	}
	cout << ans << '\n';
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}