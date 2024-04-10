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
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};
int dist[nax][nax];
bool vis[nax][nax];
pair<int,int> parent[nax][nax];

int h, w;

bool inside(int row, int col) {
	return 0 <= row && row < h && 0 <= col && col < w;
}

bool is_island(int row, int col) {
	for(int dir = 0; dir < 4; ++dir) {
		int r2 = row + dx[dir];
		int c2 = col + dy[dir];
		if(inside(r2, c2) && grid[r2][c2] == grid[row][col]) {
			return false;
		}
	}
	return true;
}

int main() {
	int q;
	scanf("%d%d%d", &h, &w, &q);
	for(int row = 0; row < h; ++row) {
		scanf("%s", grid[row]);
	}
	vector<pair<int,int>> kol;
	for(int row = 0; row < h; ++row) {
		for(int col = 0; col < w; ++col) {
			if(!is_island(row, col)) {
				kol.emplace_back(row, col);
				vis[row][col] = true;
				parent[row][col] = {row, col};
			}
		}
	}
	for(int i = 0; i < (int) kol.size(); ++i) {
		int row = kol[i].first;
		int col = kol[i].second;
		for(int dir = 0; dir < 4; ++dir) {
			int r2 = row + dx[dir];
			int c2 = col + dy[dir];
			if(inside(r2, c2) && !vis[r2][c2]) {
				dist[r2][c2] = dist[row][col] + 1;
				vis[r2][c2] = true;
				kol.emplace_back(r2, c2);
				parent[r2][c2] = parent[row][col];
			}
		}
	}
	if(kol.empty()) {
		debug() << "SPEC";
	}
	while(q--) {
		int row, col;
		long long turn;
		scanf("%d%d%lld", &row, &col, &turn);
		row--;
		col--;
		int answer = grid[row][col] - '0';
		if(!kol.empty()) {
			debug() << imie(dist[row][col]) imie(parent[row][col]);
			if(dist[row][col] <= turn) {
				// infected
				tie(row, col) = parent[row][col];
				answer = grid[row][col] - '0';
				if(turn % 2) {
					answer ^= 1;
				}
			}
		}
		printf("%d\n", answer);
	}
}