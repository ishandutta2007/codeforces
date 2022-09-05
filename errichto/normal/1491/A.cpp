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
	int n, q;
	scanf("%d%d", &n, &q);
	vector<int> a(n);
	int ones = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if(a[i]) {
			ones++;
		}
	}
	while(q--) {
		int type;
		scanf("%d", &type);
		if(type == 1) {
			int x;
			scanf("%d", &x);
			x--;
			if(a[x]) ones--;
			a[x] = !a[x];
			if(a[x]) ones++;
		}
		else {
			int k;
			scanf("%d", &k);
			if(k <= ones) {
				puts("1");
			}
			else {
				puts("0");
			}
		}
	}
}