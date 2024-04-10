#include <bits/stdc++.h>
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
// debug & operator << (debug & dd, P p) { dd << "(" << p.x << ", " << p.y << ")"; return dd; }

const int nax = 505;
#define right right_compile
#define left left_compile
int up[nax][nax], down[nax][nax], right[nax][nax], left[nax][nax];
int dp[12][nax][nax];

const int INF = 1e9 + 5;

void mini(int& a, int b) {
	a = min(a, b);
}

int main() {
	int h, w, k;
	scanf("%d%d%d", &h, &w, &k);
	const bool BAD = k % 2;
	k /= 2;
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w - 1; ++col) {
			scanf("%d", &right[row][col]);
			left[row][col+1] = right[row][col];
		}
	}
	for(int row = 0; row < h - 1; ++row) {
		for(int col = 0; col < w; ++col) {
			scanf("%d", &down[row][col]);
			up[row+1][col] = down[row][col];
		}
	}
	for(int i = 0; i <= k; ++i) {
		for(int row = 0; row < h; ++row) {
			for(int col = 0; col < w; ++col) {
				dp[i][row][col] = INF;
			}
		}
	}
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			if(BAD) {
				printf("-1 ");
				continue;
			}
			dp[0][row][col] = 0;
			for(int steps = 0; steps < k; ++steps) {
				for(int r = max(0, row - steps); r <= min(h - 1, row + steps); ++r) {
					for(int c = max(0, col - steps); c <= min(w - 1, col + steps); ++c) {
						const int me = dp[steps][r][c];
						if(me == INF) {
							continue;
						}
						if(r != 0) {
							mini(dp[steps+1][r-1][c], me + up[r][c]);
						}
						if(c != 0) {
							mini(dp[steps+1][r][c-1], me + left[r][c]);
						}
						mini(dp[steps+1][r+1][c], me + down[r][c]);
						mini(dp[steps+1][r][c+1], me + right[r][c]);
						dp[steps][r][c] = INF;
					}
				}
			}
			int answer = INF;
			int steps = k;
			for(int r = max(0, row - steps); r <= min(h - 1, row + steps); ++r) {
				for(int c = max(0, col - steps); c <= min(w - 1, col + steps); ++c) {
					mini(answer, 2 * dp[steps][r][c]);
					dp[steps][r][c] = INF;
				}
			}
			printf("%d ", answer);
			// for(int r = -k; r <= k; ++r) {
				// for(int c = -k; c <= k; ++c) {
					// if(inside(row + r, col + c)) {
						
					// }
					// else {
						
					// }
				// }
			// }
		}
		puts("");
	}
}