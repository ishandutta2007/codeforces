#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

using ll = long long;

const int nax = 55;
char grid[nax][nax];
int dp[nax][nax][nax][nax];
bool empty_row[nax][nax][nax];
bool empty_col[nax][nax][nax];

const int INF = 1e9 + 5;

void mini(int& a, int b) {
	a = min(a, b);
}

int main() {
	int n;
	scanf("%d", &n);
	for(int row = 0; row < n; ++row) {
		scanf("%s", grid[row]);
		for(int col = 0; col < n; ++col) {
			dp[row][row][col][col] = (grid[row][col] == '#');
		}
	}
	for(int row = 0; row < n; ++row) {
		for(int col = 0; col < n; ++col) {
			for(int c2 = col; c2 < n; ++c2) {
				empty_row[row][col][c2] = true;
				for(int i = col; i <= c2; ++i) {
					if(grid[row][i] == '#') {
						empty_row[row][col][c2] = false;
						break;
					}
				}
			}
		}
	}
	for(int col = 0; col < n; ++col) {
		for(int row = 0; row < n; ++row) {
			for(int r2 = row; r2 < n; ++r2) {
				empty_col[col][row][r2] = true;
				for(int i = row; i <= r2; ++i) {
					if(grid[i][col] == '#') {
						empty_col[col][row][r2] = false;
						break;
					}
				}
			}
		}
	}
	for(int row = n - 1; row >= 0; --row) {
		for(int r2 = row; r2 < n; ++r2) {
			for(int col = n - 1; col >= 0; --col) {
				for(int c2 = col; c2 < n; ++c2) {
					if(row == r2 && col == c2) {
						continue;
					}
					int& me = dp[row][r2][col][c2];
					me = max(r2 - row + 1, c2 - col + 1);
					if(empty_row[row][col][c2]) {
						if(row == r2) {
							me = 0;
						}
						else {
							me = dp[row+1][r2][col][c2];
						}
					}
					if(empty_row[r2][col][c2]) {
						if(row == r2) {
							me = 0;
						}
						else {
							me = dp[row][r2-1][col][c2];
						}
					}
					if(empty_col[col][row][r2]) {
						if(col == c2) {
							me = 0;
						}
						else {
							me = dp[row][r2][col+1][c2];
						}
					}
					if(empty_col[c2][row][r2]) {
						if(col == c2) {
							me = 0;
						}
						else {
							me = dp[row][r2][col][c2-1];
						}
					}
					for(int rr = row; rr < r2; ++rr) {
						mini(me, dp[row][rr][col][c2] + dp[rr+1][r2][col][c2]);
					}
					for(int cc = col; cc < c2; ++cc) {
						mini(me, dp[row][r2][col][cc] + dp[row][r2][cc+1][c2]);
					}
					// debug() << imie(row) imie(r2) imie(col) imie(c2) imie(me);
				}
			}
		}
	}
	printf("%d\n", dp[0][n-1][0][n-1]);
}