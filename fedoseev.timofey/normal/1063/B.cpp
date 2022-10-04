#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 2007;

int d[N][N];
int mx[N][N];
int my[N][N];

vector <int> dx = {-1, 1, 0, 0};
vector <int> dy = {0, 0, -1, 1};

const int Inf = 1e9 + 228;

int n, m;

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    int r, c, X, Y;
    cin >> r >> c >> X >> Y;
    --r, --c;
    vector <vector <int>> a(n, vector <int> (m));
    for (int i = 0; i < n; ++i) {
    	string s;
    	cin >> s;
    	for (int j = 0; j < m; ++j) {
    		if (s[j] == '*') a[i][j] = 0;
    		else a[i][j] = 1;
    	}
    }
    deque <pair <int, int>> q;
    for (int i = 0; i < N; ++i) {
    	for (int j = 0; j < N; ++j) {
    		d[i][j] = Inf;
    		mx[i][j] = Inf;
    		my[i][j] = Inf;
    	}
    }
    d[r][c] = 0;
    mx[r][c] = 0;
  	my[r][c] = 0;
  	q.push_back({r, c});
    while (!q.empty()) {
    	int x = q.front().first;
    	int y = q.front().second;
    	q.pop_front();
    	for (int i = 0; i < 2; ++i) {
    		int tx = x + dx[i];
    		int ty = y + dy[i];
    		if (ok(tx, ty) && a[tx][ty] && d[tx][ty] > d[x][y]) {
    			d[tx][ty] = d[x][y];
    			mx[tx][ty] = mx[x][y];
    			my[tx][ty] = my[x][y];
    			q.push_front({tx, ty});
    		}
    	}
    	for (int i = 2; i < 4; ++i) {
    		int tx = x + dx[i];
    		int ty = y + dy[i];
    		if (ok(tx, ty) && a[tx][ty] && d[tx][ty] > d[x][y] + 1) {
    			d[tx][ty] = d[x][y] + 1;
    			mx[tx][ty] = mx[x][y] + (i == 2);
    			my[tx][ty] = my[x][y] + (i == 3);
    			q.push_back({tx, ty});
    		}
    	}
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < m; ++j) {
    		if (mx[i][j] <= X && my[i][j] <= Y) ++ans;
    	}
    }
    cout << ans << '\n';
}