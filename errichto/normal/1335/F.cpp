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

string read_row() {
	static char s[int(1e6+5)];
	scanf("%s", s);
	return string(s);
}

void test_case() {
	int H, W;
	scanf("%d%d", &H, &W);
	vector<string> grid(H), grid_color(H);
	for(string& s : grid_color) {
		s = read_row();
	}
	for(string& s : grid) {
		s = read_row();
	}
	// TODO: read white & black
	// binary lifting / jump pointers
	vector<vector<pair<int,int>>> parent(H, vector<pair<int,int>>(W));
	// parent[5][2] = {5, 3}
	for(int row = 0; row < H; ++row) {
		for(int col = 0; col < W; ++col) {
			int r2 = row, c2 = col;
			char ch = grid[row][col];
			if(ch == 'U') r2--;
			if(ch == 'D') r2++;
			if(ch == 'L') c2--;
			if(ch == 'R') c2++;
			parent[row][col] = {r2, c2};
		}
	}
	for(int rep = 0; rep < 22; ++rep) {
		vector<vector<pair<int,int>>> new_parent(H, vector<pair<int,int>>(W));
		for(int row = 0; row < H; ++row) {
			for(int col = 0; col < W; ++col) {
				pair<int,int> tmp = parent[row][col];
				new_parent[row][col] = parent[tmp.first][tmp.second];
			}
		}
		parent = new_parent;
	}
	vector<vector<bool>> anybody_can_reach_you(H, vector<bool>(W));
	vector<vector<bool>> black_can_reach_you(H, vector<bool>(W));
	for(int row = 0; row < H; ++row) {
		for(int col = 0; col < W; ++col) {
			pair<int,int> par = parent[row][col];
			anybody_can_reach_you[par.first][par.second] = true;
			if(grid_color[row][col] == '0') {
				black_can_reach_you[par.first][par.second] = true;
			}
		}
	}
	int any = 0, blacks = 0;
	for(int row = 0; row < H; ++row) {
		for(int col = 0; col < W; ++col) {
			if(anybody_can_reach_you[row][col]) {
				++any;
			}
			if(black_can_reach_you[row][col]) {
				++blacks;
			}
		}
	}
	printf("%d %d\n", any, blacks);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}