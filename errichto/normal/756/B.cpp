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
struct debug{
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
sim dor(const c &) { ris; }
#endif
};
#define imie(x) " [" << #x ": " << (x) << "] "

const int nax = 1e5 + 5;
int t[nax];
map<int,int> m;

int f(int x) {
	auto it = m.upper_bound(x);
	--it;
	return it -> second;
}

int main() {
	int n;
	scanf("%d", &n);
	m[-10000] = 0;
	int already = 0;
	for(int i = 0; i < n; ++i) {
		scanf("%d", &t[i]);
		int x = min({f(t[i]-1) + 20, f(t[i]-90) + 50, f(t[i]-1440) + 120});
		m[t[i]] = x;
		printf("%d\n", x - already);
		already = x;
	}
}