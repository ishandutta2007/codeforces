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

const int N = 11;
const int Inf = 1e9;

vector <int> dx[3] = {{-1, 0, 0, 1}, {-1, -1, 1, 1}, {-1, 1, 2, 2, 1, -1, -2, -2}};
vector <int> dy[3] = {{0, -1, 1, 0}, {-1, 1, -1, 1}, {-2, -2, -1, 1, 2, 2, -1, 1}};
int n;

pair <int, int> g[3][3][N][N][N][N];
int a[N][N];

bool ok(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void build() {
	for (int x = 0; x < n; ++x) {
		for (int y = 0; y < n; ++y) {
			for (int t = 0; t < 3; ++t) {
				for (int i = 0; i < dx[t].size(); ++i) {
					if (t == 2) {
						int cx = x + dx[t][i];
						int cy = y + dy[t][i];
						if (ok(cx, cy)) {
							g[t][t][x][y][cx][cy] = {1, 0};
						}
					}
					else {
						for (int k = 1; k <= n; ++k) {
							int cx = x + dx[t][i] * k;
							int cy = y + dy[t][i] * k;
							if (ok(cx, cy)) {
								g[t][t][x][y][cx][cy] = {1, 0};
							}
						}
					}
				}
			}
		}
	}
}

pair <int, int> sm(pair <int, int> a, pair <int, int> b) {
	return {a.first + b.first, a.second + b.second};
}

void count(int x, int y, vector <pair <int, int>> &t) {
	if (a[x][y] == n * n) {
		return;
	}
	int ix = -1, jx = -1;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[x][y] + 1 == a[i][j]) {
				ix = i;
				jx = j;
			}
		}
	}
	vector <pair <int, int>> nt(3, {Inf, Inf});
	for (int t1 = 0; t1 < 3; ++t1) {
		for (int t2 = 0; t2 < 3; ++t2) {
			nt[t2] = min(nt[t2], sm(t[t1], g[t1][t2][x][y][ix][jx]));
		}
	}
	t = nt;
	count(ix, jx, t);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin >> n;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		cin >> a[i][j];
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		for (int k = 0; k < n; ++k) {
    			for (int t = 0; t < n; ++t) {
    				for (int t1 = 0; t1 < 3; ++t1) {
    					for (int t2 = 0; t2 < 3; ++t2) {
    						g[t1][t2][i][j][k][t] = {Inf, Inf};
    					}
    				}
    			}
    		}
    	}
    }
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		for (int t1 = 0; t1 < 3; ++t1) {
    			for (int t2 = 0; t2 < 3; ++t2) {
    				if (t1 == t2) {
    					g[t1][t2][i][j][i][j] = {0, 0};
    				}
    				else {
    					g[t1][t2][i][j][i][j] = {1, 1};
    				}
    			}
    		}
    	}
    }
    build();
    for (int t3 = 0; t3 < 3; ++t3) {
    	for (int kx = 0; kx < n; ++kx) {
    		for (int ky = 0; ky < n; ++ky) {
    			for (int t1 = 0; t1 < 3; ++t1) {
	    			for (int ix = 0; ix < n; ++ix) {
	    				for (int iy = 0; iy < n; ++iy) {
	    					for (int t2 = 0; t2 < 3; ++t2) {
	    						for (int jx = 0; jx < n; ++jx) {
	    							for (int jy = 0; jy < n; ++jy) {
    									g[t1][t2][ix][iy][jx][jy] = min(g[t1][t2][ix][iy][jx][jy], sm(g[t1][t3][ix][iy][kx][ky], g[t3][t2][kx][ky][jx][jy]));
    								}
								}
							}
						}
					}
				}
			}
		}
    }
    int ix = -1, jx = -1;
    for (int i = 0; i < n; ++i) {
    	for (int j = 0; j < n; ++j) {
    		if (a[i][j] == 1) {
    			ix = i;
    			jx = j;
    		}
    	}
    }
    vector <pair <int, int>> t(3);
    count(ix, jx, t);
  	pair <int, int> ans = {Inf, Inf};
  	for (int i = 0; i < 3; ++i) {
  		ans = min(ans, t[i]);
  	}
  	cout << ans.first << ' ' << ans.second << '\n';
}