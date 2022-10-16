// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str to_string

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

const int N = 64;

bool have[N][N];

void run() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		have[s[1] - '1'][s[0] - 'a'] = 1;
	}
	bool rev = n > 32;
	if (rev) {
		n = 64 - n;
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				have[r][c] ^= 1;
			}
		}
	}
	int put = 0;
	vector<string> ans;
	vector<pair<int, int>> d = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
	vector<pair<int, int>> order;
	if (rev) {
		for (int r = 7; r >= 0; r--) {
			for (int c = 7; c >= 0; c--) {
				order.emplace_back(r, c);
			}
		}
	} else {
		for (int r = 0; r < 8; r++) {
			for (int c = 0; c < 8; c++) {
				order.emplace_back(r, c);
			}
		}
	}
	for (auto[r, c] : order) {
		if (put == n) {
			break;
		}
		if (have[r][c]) {
			put++;
			continue;
		}
		queue<pair<int, int>> q;
		q.push({r, c});
		vector<vector<bool>> used(8, vector<bool>(8));
		vector<vector<pair<int, int>>> prev(8, vector<pair<int, int>>(8));
		used[r][c] = 1;
		while (!q.empty()) {
			auto u = q.front();
			q.pop();
			bool found = 0;
			for (auto[dx, dy] : d) {
				int x = u.first + dx, y = u.second + dy;
				if (0 <= x && x < 8 && 0 <= y && y < 8) {
					if (!used[x][y]) {
						if (have[x][y]) {
							if (!rev && (x < r || x == r && y < c) || rev && (x > r || x == r && y > c)) {
								continue;
							} else {
								prev[x][y] = u;
								while (make_pair(x, y) != make_pair(r, c)) {
									int px = prev[x][y].first, py = prev[x][y].second;
									have[x][y] ^= 1;
									have[px][py] ^= 1;
									ans.push_back(string(1, (char) ('a' + (rev ? py : y))) + str(rev ? px + 1 : x + 1) + "-" + string(1, (char) ('a' + (rev ? y : py))) + str(rev ? x + 1 : px + 1));
									assert(have[x][y] != have[px][py]);
									tie(x, y) = prev[x][y];
								}
								found = 1;
								break;
							}
						}
						used[x][y] = 1;
						q.push({x, y});
						prev[x][y] = u;
					}
				}
			}
			if (found) {
				break;
			}
		}
		put++;
	}
	cout << szof(ans) << "\n";
	for (string s : ans) {
		cout << s << "\n";
	}
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}