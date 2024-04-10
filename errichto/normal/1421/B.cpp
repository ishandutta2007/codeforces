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
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		vector<vector<int>> a(n, vector<int>(n));
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				char ch;
				scanf(" %c", &ch);
				a[i][j] = (ch == '1');
				// scanf("%d", &a[i][j]);
			}
		}
		bool found = false;
		for(int rep = 0; rep < 2; ++rep) {
			vector<pair<int,int>> changed;
			if(a[0][1] != rep) {
				changed.emplace_back(0, 1);
			}
			if(a[1][0] != rep) {
				changed.emplace_back(1, 0);
			}
			if(a[n-2][n-1] != !rep) {
				changed.emplace_back(n-2, n-1);
			}
			if(a[n-1][n-2] != !rep) {
				changed.emplace_back(n-1, n-2);
			}
			if((int) changed.size() <= 2) {
				printf("%d\n", (int) changed.size());
				for(pair<int,int> p : changed) {
					printf("%d %d\n", p.first + 1, p.second + 1);
				}
				found = true;
				break;
			}
		}
		assert(found);
		// int need = a[0][1] + a[1][0] + !a[n-2][n-1] + !a[n-1][n-2];
		// if(need <= 2) {
			// a[0][1] = a[1][0] = 0;
			// a[n-2][n-1] = a[n-1][n-2] = 1;
		// }
		// else {
			// a[0][1] = a[1][0] = 1;
			// a[n-2][n-1] = a[n-1][n-2] = 0;
		// }
	}
}