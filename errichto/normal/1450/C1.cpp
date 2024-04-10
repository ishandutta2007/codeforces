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

char grid[305][305];

void test_case() {
	int n;
	scanf("%d", &n);
	vector<int> o(3), x(3);
	int k = 0;
	for(int row = 0; row < n; ++row) {
		scanf("%s", grid[row]);
		for(int col = 0; col < n; ++col) {
			if(grid[row][col] == 'X') {
				++k;
				++x[(row+col)%3];
			}
			if(grid[row][col] == 'O') {
				++k;
				++o[(row+col)%3];
			}
		}
	}
	vector<pair<int,int>> order;
	for(int i = 0; i < 3; ++i) {
		order.emplace_back(o[i] + x[i], i);
	}
	sort(order.begin(), order.end());
	int blue = order[0].second; // -> x
	int red = order[1].second; // -> o
	if(o[blue] + x[red] > o[red] + x[blue]) {
		swap(blue, red);
	}
	int operations = 0;
	for(int row = 0; row < n; ++row) {
		for(int col = 0; col < n; ++col) {
			if((row + col) % 3 == blue && grid[row][col] == 'O') {
				++operations;
				grid[row][col] = 'X';
			}
			if((row + col) % 3 == red && grid[row][col] == 'X') {
				++operations;
				grid[row][col] = 'O';
			}
		}
		printf("%s\n", grid[row]);
	}
	debug() << imie(operations) imie(k);
	assert(operations <= k / 3);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}


// ->
// .......b.
// ......b..
// .....b...
// ...xb....
// ..ooo.... -> ..oox....
// ..bx.....
// .b.......


// .......b.
// ......b..
// .....b...
// ...xb....
// ..oxo.... -> ..oox.... with 2 operations
// ..bx.....
// .b.......

// 1.5 * k/3