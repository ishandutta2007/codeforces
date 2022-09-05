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

const int nax = 1005;
pair<int,int> grid[nax][nax];
int dp[nax][nax];
const int INF = 1e9 + 5;

int main() {
	int n;
	scanf("%d", &n);
	bool can_one = false;
	string spec;
	for(int row = 1; row <= n; ++row) {
		for(int col = 1; col <= n; ++col) {
			int x;
			scanf("%d", &x);
			if(x == 0) {
				can_one = true;
				if(spec.empty()) {
					spec += string(row - 1, 'D');
					spec += string(col - 1, 'R');
					spec += string(n - row, 'D');
					spec += string(n - col, 'R');
				}
				// x = 1;
				// puts("1");
				// string s(n - 1, 'D');
				// s += string(n - 1, 'R');
				// printf("%s\n", s.c_str());
				// return 0;
				x = 4 * 25;
			}
			while(x % 2 == 0) {
				x /= 2;
				grid[row][col].first++;
			}
			while(x % 5 == 0) {
				x /= 5;
				grid[row][col].second++;
			}
		}
	}
	pair<int, string> answer = {INF, ""};
	for(int row = 0; row <= n; ++row) {
		for(int col = 0; col <= n; ++col) {
			dp[row][col] = INF;
		}
	}
	for(int turn : {0, 1}) {
		for(int row = 1; row <= n; ++row) {
			for(int col = 1; col <= n; ++col) {
				swap(grid[row][col].first, grid[row][col].second);
			}
		}
		
		for(int row = 1; row <= n; ++row) {
			for(int col = 1; col <= n; ++col) {
				dp[row][col] = min(dp[row-1][col], dp[row][col-1]);
				if(row == 1 && col == 1) {
					dp[row][col] = 0;
				}
				dp[row][col] += grid[row][col].first;
			}
		}
		string s;
		int value = dp[n][n];
		int row = n, col = n;
		while(row != 1 || col != 1) {
			dp[row][col] -= grid[row][col].first;
			if(dp[row][col] == dp[row-1][col]) {
				s += "D";
				--row;
			}
			else if(dp[row][col] == dp[row][col-1]) {
				s += "R";
				--col;
			}
			else {
				assert(false);
			}
		}
		reverse(s.begin(), s.end());
		answer = min(answer, {value, s});
	}
	if(can_one && answer.first != 0) {
		puts("1");
		// string s(n - 1, 'D');
		// s += string(n - 1, 'R');
		printf("%s\n", spec.c_str());
		return 0;
	}
	printf("%d\n", answer.first);
	printf("%s\n", answer.second.c_str());
}