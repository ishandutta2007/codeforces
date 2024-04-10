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
 
using ll = long long;

const int nax = 105;
char grid[nax][nax];

void test_case() {
	int h, w, k;
	scanf("%d%d%d", &h, &w, &k);
	int total = 0;
	vector<pair<int,int>> order;
	for(int row = 0; row < h; ++row) {
		scanf("%s", grid[row]);
		for(int col = 0; col < w; ++col) {
			if(grid[row][col] == 'R') {
				++total;
			}
		}
		if(row % 2) {
			for(int col = 0; col < w; ++col) {
				order.emplace_back(row, col);
			}
		}
		else {
			for(int col = w - 1; col >= 0; --col) {
				order.emplace_back(row, col);
			}
		}
	}
	int i = 0;
	for(int chicken = 0; chicken < k; ++chicken) {
		int should = total / (k - chicken);
		total -= should;
		char me;
		if(chicken < 26) {
			me = 'a' + chicken;
		}
		else if(chicken < 26 + 26) {
			me = 'A' + (chicken - 26);
		}
		else {
			me = '0' + (chicken - 26 - 26);
		}
		while(should || (chicken == k - 1 && i < (int) order.size())) {
			pair<int,int> p = order[i++];
			if(grid[p.first][p.second] == 'R') {
				--should;
			}
			grid[p.first][p.second] = me;
		}
	}
	for(int row = 0; row < h; ++row) {
		printf("%s\n", grid[row]);
	}
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}