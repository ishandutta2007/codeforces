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
	cin >> n;
	vector<vector<bool>> vis(n, vector<bool>(n));
	for(int rep = 0; rep < n * n; ++rep) {
		int bad;
		cin >> bad;
		bad--;
		vector<int> output;
		for(int row = 0; row < n; ++row) {
			for(int col = 0; col < n; ++col) {
				if(!vis[row][col] && (row + col) % 2 != bad) {
					output = {(row + col) % 2, row, col};
				}
			}
		}
		if(output.empty()) {
			for(int row = 0; row < n; ++row) {
				for(int col = 0; col < n; ++col) {
					if(!vis[row][col]) {
						output = {2, row, col};
					}
				}
			}
		}
		assert(!output.empty());
		vis[output[1]][output[2]] = true;
		printf("%d %d %d\n", output[0] + 1, output[1] + 1, output[2] + 1);
		fflush(stdout);
	}
}


// 12121
// 21212
// 12121
// 21212