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



int main() {
	int n;
	scanf("%d", &n);
	vector<vector<long long>> grid(n, vector<long long>(n));
	for(int row = 0; row < n; ++row) {
		for(int col = 0; col < n; ++col) {
			int s = row + col;
			long long tmp = (1LL << s);
			if(row % 2) grid[row][col] = tmp;
			printf("%lld ", grid[row][col]);
		}
		puts("");
	}
	fflush(stdout);
	int q;
	scanf("%d", &q);
	while(q--) {
		long long value;
		scanf("%lld", &value);
		int row = 0, col = 0;
		puts("1 1");
		while(make_pair(row, col) != make_pair(n-1,n-1)) {
			if(row == n - 1) col++;
			else if(col == n - 1) row++;
			else {
				if(grid[row][col+1]) {
					if(value & grid[row][col+1]) {
						col++;
					}
					else {
						row++;
					}
				}
				else {
					assert(grid[row+1][col]);
					if(value & grid[row+1][col]) {
						row++;
					}
					else {
						col++;
					}
				}
			}
			printf("%d %d\n", row + 1, col + 1);
		}
		fflush(stdout);
	}
}