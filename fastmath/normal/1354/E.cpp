#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <random>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <cmath>
#include <bitset>
#include <iomanip>
//#include <unordered_map>

using namespace std;

template<typename T> void uin(T &a, T b) {if (b < a) a = b;}
template<typename T> void uax(T &a, T b) {if (b > a) a = b;}

#define int long long
#define right right228
#define left left228
#define all(v) v.begin(), v.end()

const int N = 5000 + 228;

vector<int> g[N];
int color[N], answer[N];
bool change[N];
bool bip = 1;
int the_size = 0;
int white = 0;

vector<int> order;

void dfs(int v, int col) {
	order.emplace_back(v);
	color[v] = col;
	if (color[v] == 1) ++white;
	++the_size;
	for (int to : g[v]) {
		if (!color[to]) dfs(to, 3 - color[v]);
		else if (color[to] == color[v]) bip = 0;
	}
}

bool dp[N][N], take[N][N];

int n1, n2, n3;
int rest() {
	if (n1) {
		--n1;
		return 1;
	}
	--n3;
	return 3;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
	int n, m;
	cin >> n >> m;
	cin >> n1 >> n2 >> n3;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}
	int kekos = 0;
	vector< pair<int, int> > kek;
	for (int v = 1; v <= n; ++v) {
		if (!color[v]) {
			order.clear();
			the_size = white = 0;
			bip = 1;
			dfs(v, 1);
			if (bip == 0) {
				cout << "NO\n";
				return 0;
			}
			int mn = min(white, the_size - white);
			n2 -= mn;
			kek.emplace_back(v, the_size - 2 * mn);
		}
	}
	if (n2 < 0) {
		cout << "NO\n";
		return 0;
	}
	dp[0][0] = 1;
	int sz = (int)kek.size();
	for (int i = 0; i < sz; ++i) {
		for (int j = 0; j <= n2; ++j) {
			if (!dp[i][j]) continue;
			dp[i + 1][j] = 1;
			take[i + 1][j] = 0;
			if (j + kek[i].second <= n2) {
				dp[i + 1][j + kek[i].second] = 1;
				take[i + 1][j + kek[i].second] = 1;
			}
		}
	}
	if (dp[sz][n2] == 0) {
		cout << "NO\n";
		return 0;
	}
	int i = sz;
	int j = n2;
	while(i) {
		if (take[i][j]) {
			change[kek[i - 1].first] = 1;
			j -= kek[i - 1].second;
			--i;
		} else {
			--i;
		}
	}
	for (int i = 1; i <= n; ++i) color[i] = 0;
	for (int i = 1; i <= n; ++i) {
		if (!color[i]) {
			order.clear();
			the_size = white = 0;
			bip = 1;
			dfs(i, 1);
			if (change[i]) {
				if (white == min(white, the_size - white)) {
					for (int x : order) {
						if (color[x] == 1) {
							answer[x] = rest();
						} else {
							answer[x] = 2;
						}
					}
				} else {
					for (int x : order) {
						if (color[x] == 1) {
							answer[x] = 2;
						} else {
							answer[x] = rest();
						}
					}
				}
			} else {
				if (white == min(white, the_size - white)) {
					for (int x : order) {
						if (color[x] == 1) {
							answer[x] = 2;
						} else {
							answer[x] = rest();
						}
					}
				} else {
					for (int x : order) {
						if (color[x] == 1) {
							answer[x] = rest();
						} else {
							answer[x] = 2;
						}
					}
				}
			}
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; ++i) {
		cout << answer[i];
	}
	cout << '\n';
	return 0;
}

/*


*/