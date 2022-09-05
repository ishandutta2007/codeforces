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

void test_case() {
	int n, len;
	scanf("%d%d", &n, &len);
	vector<int> a(n + 2);
	a[0] = 0;
	a[n+1] = len;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
	}
	int pos1 = 0, pos2 = n + 1;
	double t1 = 0, t2 = 0;
	double s1 = 1, s2 = 1;
	while(pos1 + 1 < pos2) {
		double x = (a[pos1+1] - a[pos1]) / s1;
		double y = (a[pos2] - a[pos2-1]) / s2;
		if(t1 + x < t2 + y) {
			t1 += x;
			pos1++;
			s1++;
		}
		else {
			t2 += y;
			pos2--;
			s2++;
		}
	}
	double dist = a[pos2] - a[pos1];
	if(t1 < t2) {
		dist -= (t2 - t1) * s1;
	}
	else {
		dist -= (t1 - t2) * s2;
	}
	double T = max(t1, t2) + dist / (s1 + s2);
	printf("%.12lf\n", T);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		test_case();
	}
}