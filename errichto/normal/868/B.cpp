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

const double eps = 1e-8;

bool order(double a, double b, double c) {
	return a < b && b < c;
}

int main() {
	double h, m, s, t1, t2;
	cin >> h >> m >> s >> t1 >> t2;
	s /= 60;
	m = m / 60 + s / 60;
	h = h / 12 + m / 12;
	if(m >= 1 - eps) m -= 1;
	if(h >= 1 - eps) h -= 1;
	t1 /= 12;
	t2 /= 12;
	if(t1 >= 1 - eps) t1 -= 1;
	if(t2 >= 1 - eps) t2 -= 1;
	if(t1 > t2) swap(t1, t2);
	bool should = order(t1, h, t2);
	if(should == order(t1, m, t2) && should == order(t1, s, t2))
		puts("YES");
	else
		puts("NO");
}