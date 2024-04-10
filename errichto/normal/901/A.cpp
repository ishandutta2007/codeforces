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



int main() {
	int h;
	scanf("%d", &h);
	int n = 0;
	vector<int> in(h + 1);
	vector<vector<int>> they(h + 1);
	int nxt = 1;
	for(int i = 0; i <= h; ++i) {
		scanf("%d", &in[i]);
		n += in[i];
		for(int rep = 0; rep < in[i]; ++rep) {
			they[i].push_back(nxt++);
		}
	}
	assert(in[0] == 1);
	for(int where = 1; where < h; ++where)
		if(in[where] >= 2 && in[where+1] >= 2) {
			puts("ambiguous");
			for(int turn : {0, 1}) {
				vector<int> print;
				print.push_back(0);
				for(int level = 1; level <= h; ++level) {
					if(level == where + 1 && turn == 1) {
						print.push_back(they[level-1][1]);
						for(int i = 1; i < (int) they[level].size(); ++i)
							print.push_back(they[level-1][0]);
					}
					else {
						for(int x : they[level]) print.push_back(they[level-1][0]);
					}
				}
				for(int i = 0; i < (int) print.size(); ++i) {
					printf("%d", print[i]);
					if(i != (int) print.size() - 1) printf(" ");
				}
				puts("");
			}
			return 0;
		}
	puts("perfect");
}