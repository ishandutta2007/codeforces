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
	vector<pair<int, int>> who(n, make_pair(-1, -1));
	for(int i = 0; i < 2 * n; ++i) {
		int a;
		cin >> a;
		--a;
		if (who[a].first == -1)
			who[a].first = i;
		else
			who[a].second = i;
	}
	pair<int, int> now = {0, 0};
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		ans += min(abs(now.first - who[i].first) + abs(now.second - who[i].second), 
			abs(now.first - who[i].second) + abs(now.second - who[i].first));
		now = {who[i].first, who[i].second};
	}
	cout << ans;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}