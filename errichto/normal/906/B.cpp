#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
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

int r(int a, int b) {
	return a + rand() % (b - a + 1);
}

int main() {
	int h, w;
	scanf("%d%d", &h, &w);
	//~ vector<vector<int>> grid(h, vector<int>(w));
	int n = h * w;
	vector<int> perm(n);
	for(int i = 0; i < n; ++i) perm[i] = i;
	auto bad = [&] (int a, int b) {
		if(a > b) swap(a, b);
		if(a + w == b) return true;
		if(a + 1 == b && b % w != 0) return true;
		return false;
	};
	int tries = 0;
	
	while(true) {
		//~ puts("x");
		if(tries >= 10000) {
			puts("NO");
			return 0;
		}
		++tries;
		random_shuffle(perm.begin(), perm.end());
		//~ perm = {5, 2, 7, 1, 3, 8, 6, 4};
		//~ for(int & x : perm) --x;
		bool ok = true;
		for(int row = 0; row < h && ok; ++row)
			for(int col = 0; col < w && ok; ++col) {
				int limit = 10;
				while(limit >= 1) {
					--limit;
					if((row && bad(perm[row*w+col], perm[(row-1)*w+col]))
						|| (col && bad(perm[row*w+col], perm[row*w+col-1]))) {
							if(row == h - 1 && col == w - 1) {
								limit = 0;
								break;
							}
							else {
								swap(perm[row*w+col], perm[r(row*w+col+1, h * w - 1)]);
							}
						}
					else break;
				}
				if(limit == 0) ok = false;
			}
		if(ok) {
			puts("YES");
			for(int row = 0; row < h; ++row) {
				for(int col = 0; col < w; ++col) {
					printf("%d", perm[row*w+col] + 1);
					if(col != w - 1) printf(" ");
				}
				puts("");
			}
			cerr << tries << "\n";
			return 0;
		}
		
	}
	assert(false);
}