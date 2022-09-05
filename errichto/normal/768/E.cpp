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

map<set<int>, int> mapka[65];

int f(int x, set<int> & s) {
	if(mapka[x].count(s)) return mapka[x][s];
	set<int> values;
	for(int a = 1; a <= x; ++a)
		if(!s.count(a)) {
			s.insert(a);
			values.insert(f(x - a, s));
			s.erase(a);
		}
	for(int i = 0; true; ++i) if(!values.count(i))
		return mapka[x][s] = i;
}

int main() {
	int n;
	scanf("%d", &n);
	int total = 0;
	while(n--) {
		int x;
		scanf("%d", &x);
		int p = 1, s = 1;
		while(x >= s + p + 1) {
			++p;
			s += p;
		}
		debug() << imie(p);
		//int p = 0;
		//while(x >= (1 << (p + 1)) - 1) ++p;
		//set<int> tmp;
		//cout << f(x, tmp) << "\n";
		//debug() << imie(f(x, tmp));
		total ^= p;
	}
	puts(total ? "NO" : "YES");
}