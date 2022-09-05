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

// .................
// .....###.###.....
// .....#.#.#.#.....
// .....#######.....
// .......#.#.......
// .......###.......
// .................

int main() {
	int n;
	scanf("%d", &n);
	n++;
	set<pair<int,int>> answer;
	auto f = [&](int x, int y) {
		for(int i = 0; i < 3; ++i) {
			for(int j = 0; j < 3; ++j) {
				if(i != 1 || j != 1) {
					answer.insert({x + i, y + j});
				}
			}
		}
	};
	f(0, 0);
	for(int i = 1; i < n; ++i) {
		f(2 * i, (i % 2 ? -2 : 0));
	}
	printf("%d\n", (int) answer.size());
	for(pair<int,int> p : answer) {
		printf("%d %d\n", p.first, p.second);
	}
	for(int row = -4; row <= 10; ++row) {
		for(int col = -4; col <= 10; ++col) {
			if(answer.count({row, col})) {
				cerr << "#";
			}
			else {
				cerr << ".";
			}
		}
		cerr << endl;
	}
}