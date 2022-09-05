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

const int k = 10;

int r[k][2];

int main() {
	for(int i = 0; i < k; ++i)
		for(int j : {0, 1})
			r[i][j] = j;
	int n;
	scanf("%d", &n);
		debug() << imie(r[0][0]) imie(r[0][1]);
	for(int i = 0; i < n; ++i) {
		char sl[2];
		scanf("%s", sl);
		int x;
		scanf("%d", &x);
		debug() << imie(sl[0]) imie(x);
		for(int j = 0; j < k; ++j) {
			int tmp = bool(x & (1 << j));
			for(int val : {0, 1}) {
				if(sl[0] == '|') r[j][val] |= tmp;
				else if(sl[0] == '&') r[j][val] &= tmp;
				else if(sl[0] == '^') r[j][val] ^= tmp;
				else assert(false);
			}
		}
		debug() << imie(r[0][0]) imie(r[0][1]);
	}
	int tor = 0, tand = (1 << k) - 1, txor = 0;
	for(int i = 0; i < k; ++i) {
		if(r[i][0] && r[i][1]) tor |= 1 << i;
		else if(r[i][0]) txor |= 1 << i;
		else if(r[i][1]) {}
		else tand ^= 1 << i;
	}
	printf("%d\n", 3);
	printf("| %d\n", tor);
	printf("& %d\n", tand);
	printf("^ %d\n", txor);
}