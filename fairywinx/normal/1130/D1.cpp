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
	
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n, make_pair(0, 1e9));
	for(int i = 0; i < m; ++i) {
		int b, c;
		cin >> b >> c;
		a[b - 1].first++;
		a[b - 1].second = min(a[b - 1].second, (c - b + n) % n);
	}
	for(int i = 0; i < n; ++i) {
		int ans = 0;
		for(int j = 0; j < n; ++j) {
			if (a[j].first != 0) {
				ans = max(ans, (j - i + n) % n + (a[j].first - 1) * n + a[j].second);
			}
		}
		cout << ans << ' ';
	}
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}