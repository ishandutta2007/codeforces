#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//~ #define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, m; cin >> n >> m;
	vector< vector<int> > a(n, vector<int>(m));
	vector< tuple<int, int, int> > cells;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			cells.emplace_back(a[i][j], i, j);
		}
	}
	sort(begin(cells), end(cells));
	reverse(begin(cells), end(cells));
	
	set< pair<int, int> > queued;
	vector<char> hr(n), hc(m);
	int h = 0, w = 0;
	vector< vector<int> > r(n, vector<int>(m));
	vector<int> rowLe(n, -1), rowRi(n, -1);
	vector<int> colLe(m, -1), colRi(m, -1);
	
	auto canAdd = [&](int x, int y) {
		return (rowLe[x] < 0 || y == rowLe[x] - 1 || y == rowRi[x] + 1) &&
			(colLe[y] < 0 || x == colLe[y] - 1 || x == colRi[y] + 1);
	};
	
	auto doAdd = [&](int x, int y) {
		if (rowLe[x] < 0) {
			rowLe[x] = rowRi[x] = y;
		}
		if (colLe[y] < 0) {
			colLe[y] = colRi[y] = x;
		}
		rowLe[x] = min(rowLe[x], y);
		rowRi[x] = max(rowRi[x], y);
		colLe[y] = min(colLe[y], x);
		colRi[y] = max(colRi[y], x);
	};
	
	for (auto [val, x, y] : cells) {
		if (!hr[x] && !hc[y]) {
			if (h != 0 && w != 0) {
				queued.emplace(h, w-1);
				queued.emplace(h-1, w);
			}
			// cerr << val << " : f " << h << " " << w << endl;
			r[h][w] = val;
			doAdd(h, w);
			hr[x] = hc[y] = true;
			++h;
			++w;
			continue;
		}
		if (!hr[x]) {
			assert(h != 0);
			if (w > 1 && r[h-1][w-2] != 0) {
				queued.emplace(h, w-2);
			}
			// cerr << val << " : r " << h << " " << w-1 << endl;
			r[h][w-1] = val;
			doAdd(h, w-1);
			hr[x] = true;
			++h;
			continue;
		}
		if (!hc[y]) {
			assert(w != 0);
			if (h > 1 && r[h-2][w-1] != 0) {
				queued.emplace(h-2, w);
			}
			// cerr << val << " : c " << h-1 << " " << w << endl;
			r[h-1][w] = val;
			doAdd(h-1, w);
			hc[y] = true;
			++w;
			continue;
		}
		if (queued.empty()) {
			// cerr << val << " :(" << endl;
			cout << -1 << endl;
			return 0;
		}
		{
			auto [x, y] = *queued.begin();
			// cerr << val << " : " << x << " " << y << endl;
			queued.erase(queued.begin());
			doAdd(x, y);
			r[x][y] = val;
			const int dx[4] = {-1, 1, 0, 0};
			const int dy[4] = {0, 0, -1, 1};
			for (int k = 0; k < 4; ++k) {
				int nx = x + dx[k], ny = y + dy[k];
				if (0 <= nx && nx < h && 0 <= ny && ny < w && canAdd(nx, ny) && r[nx][ny] == 0) {
					queued.emplace(nx, ny);
				}
			}
		}
	}
	
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << r[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
	return 0;
}