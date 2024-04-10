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

const int nax = 105;
int grid[nax][nax], new_grid[nax][nax];

vector<pair<int,int>> operations;

void flip(int row, int col) {
	grid[row][col] = !grid[row][col];
	operations.emplace_back(row, col);
}

void ensure() {
	assert((int) operations.size() % 3 == 0);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		operations.clear();
		int h, w;
		scanf("%d%d", &h, &w);
		for(int row = 0; row < h; ++row) {
			static char s[nax];
			scanf("%s", s);
			for(int col = 0; col < w; ++col) {
				grid[row][col] = (s[col] == '1');
			}
		}
		bool flag = false;
		if(h < w) {
			for(int row = 0; row < h; ++row) {
				for(int col = 0; col < w; ++col) {
					new_grid[col][row] = grid[row][col];
				}
			}
			swap(h, w);
			flag = true;
			for(int row = 0; row < h; ++row) {
				for(int col = 0; col < w; ++col) {
					grid[row][col] = new_grid[row][col];
				}
			}
		}
		for(int row = 0; row <= h - 2; ++row) {
			for(int col = 0; col <= w - 2; ++col) {
				if(grid[row][col] || grid[row][col+1]) {
					if(!(grid[row][col] && grid[row][col+1])) {
						flip(row + 1, col);
						flip(row + 1, col + 1);
					}
					else {
						if(grid[row+1][col]) flip(row + 1, col);
						else flip(row + 1, col + 1);
					}
					if(grid[row][col]) flip(row, col);
					if(grid[row][col+1]) flip(row, col + 1);
					ensure();
				}
			}
		}
		for(int row = 0; row < h - 1; ++row) {
			for(int col = 0; col < w; ++col) {
				assert(!grid[row][col]);
			}
		}
		for(int col = 0; col <= w - 2; ++col) {
			if(col == w - 2 && grid[h-1][col] && grid[h-1][col+1]) {
				flip(h-2,w-2);
				flip(h-2,w-1);
				flip(h-1,w-1);
				ensure();
				flip(h-2,w-2);
				flip(h-2,w-1);
				flip(h-1,w-2);
				ensure();
				assert(!grid[h-1][w-1] && !grid[h-1][w-2]);
			}
			if(col == w - 2 && grid[h-1][col] && !grid[h-1][col+1]) {
				flip(h-2,w-2);
				flip(h-2,w-1);
				flip(h-1,w-2);
				ensure();
				flip(h-2,w-2);
				flip(h-1,w-2);
				flip(h-1,w-1);
				ensure();
				flip(h-1,w-2);
				flip(h-1,w-1);
				flip(h-2,w-1);
				ensure();
			}
			if(grid[h-1][col]) {
				flip(h-2, col);
				flip(h-2, col+1);
				flip(h-1, col);
				ensure();
				flip(h-2, col);
				flip(h-2, col+1);
				flip(h-1, col + 1);
				ensure();
			}
		}
		if(grid[h-1][w-1]) {
			flip(h-2,w-2);
			flip(h-2,w-1);
			flip(h-1,w-1);
			ensure();
			flip(h-2,w-2);
			flip(h-1,w-1);
			flip(h-1,w-2);
			ensure();
			flip(h-1,w-1);
			flip(h-1,w-2);
			flip(h-2,w-1);
			ensure();
		}
		debug() << imie(h) imie(w) imie(operations.size() / 3);
		assert((int) operations.size() <= 3 * h * w);
		for(int row = 0; row < h; ++row) {
			for(int col = 0; col < w; ++col) {
				assert(!grid[row][col]);
			}
		}
		printf("%d\n", (int) operations.size() / 3);
		for(int i = 0; i < (int) operations.size(); ) {
			for(int j = 0; j < 3; ++j) {
				// if(j) assert(operations[i] != operations[i-1]);
				if(flag) {
					swap(operations[i].first, operations[i].second);
				}
				printf("%d %d ", operations[i].first + 1, operations[i].second + 1);
				i++;
			}
			puts("");
		}
	}
}