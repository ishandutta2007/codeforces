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

double K(double x) { return x * x; }

int main() {
	int n, radius;
	cin >> n >> radius;
	vector<pair<int, double>> already;
	while(n--) {
		int x;
		cin >> x;
		double y = radius;
		for(pair<int,double> p : already) {
			int x2 = p.first;
			double y2 = p.second;
			if(abs(x - x2) <= 2 * radius) {
				double a = abs(x - x2);
				double tmp = K(2 * radius) - K(a);
				double h = sqrt(max(0., tmp));
				y = max(y, y2 + h);
			}
		}
		printf("%.10lf ", y);
		already.push_back(make_pair(x, y));
	}
}