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

const int nax = 1005;
char grid[nax][nax];
bool vis[nax][nax];

void check(vector<int>& v) {
	for(int i = 1; i < (int) v.size(); ++i) {
		if(v[i] != v[i-1] + 1) {
			puts("-1");
			exit(0);
		}
	}
}

int h, w;

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

vector<int> in_row[nax], in_col[nax];

void dfs(int row, int col) {
	vis[row][col] = true;
	for(int dir = 0; dir < 4; ++dir) {
		int r2 = row + dx[dir];
		int c2 = col + dy[dir];
		if(0 <= r2 && r2 < h && 0 <= c2 && c2 < w
			&& grid[r2][c2] == '#' && !vis[r2][c2]) {
			dfs(r2, c2);
		}
	}
}

int main() {
	scanf("%d%d", &h, &w);
	// bool any = false;
	for(int row = 0; row < h; ++row) {
		scanf("%s", grid[row]);
		for(int col = 0; col < w; ++col) {
			if(grid[row][col] == '#') {
				// any = true;
				in_row[row].push_back(col);
				in_col[col].push_back(row);
			}
		}
	}
	int rows = 0, cols = 0;
	for(int row = 0; row < h; ++row) {
		check(in_row[row]);
		if(!in_row[row].empty()) {
			rows++;
		}
	}
	for(int col = 0; col < w; ++col) {
		check(in_col[col]);
		if(!in_col[col].empty()) {
			cols++;
		}
	}
	debug() << imie(rows) imie(cols);
	if((rows == h) != (cols == w)) {
		puts("-1");
		return 0;
	}
	int answer = 0;
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			if(grid[row][col] == '#' && !vis[row][col]) {
				++answer;
				dfs(row, col);
			}
		}
	}
	// if(any) {
		// answer = max(answer, 1);
	// }
	printf("%d\n", answer);
}