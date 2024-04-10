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

void test_case() {
	// O(blocked)
	int len, m;
	scanf("%d%d", &len, &m);
	vector<pair<int,int>> blocked;
	for(int i = 0; i < m; ++i) {
		int row, col;
		scanf("%d%d", &row, &col);
		blocked.emplace_back(col, row);
	}
	blocked.emplace_back(0, -1);
	blocked.emplace_back(len + 1, -1);
	sort(blocked.begin(), blocked.end());
	// compression
	vector<pair<int,int>> compressed;
	int prev_col = 0;
	int shifted = 0;
	// almost this: 2, 5, 6, 10 -> 2, 3, 4, 6
	for(pair<int,int> p : blocked) {
		int col = p.first;
		int row = p.second;
		int diff = col - prev_col - 1;
		if(diff >= 4) {
			shifted += diff / 2 * 2 - 2;
			// 7 -> 6 -> 4
		}
		compressed.emplace_back(col - shifted, row);
		prev_col = col;
	}
	len = compressed.back().first - 1;
	debug() << imie(len) imie(compressed);
	vector<vector<bool>> is_blocked(2, vector<bool>(len));
	for(pair<int,int> p : compressed) {
		if(p.second != -1) {
			is_blocked[p.second-1][p.first-1] = true;
		}
	}
	// for(int row = 0; row < 2; ++row) {
		// for(int col = 0; col < len; ++col) {
			// cout << (is_blocked[row][col] ? "X" : ".");
		// }
		// cout << endl;
	// }
	for(int col = 0; col < len; ++col) {
		if(!is_blocked[0][col] && !is_blocked[1][col]) {
			is_blocked[0][col] = is_blocked[1][col] = true;
		}
		for(int row = 0; row < 2; ++row) {
			if(!is_blocked[row][col]) {
				if(col == len - 1 || is_blocked[row][col+1]) {
					puts("NO");
					return;
				}
				is_blocked[row][col+1] = true;
			}
		}
	}
	puts("YES");
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}