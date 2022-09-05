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



int main() {
	int w, l;
	scanf("%d%d", &w, &l);
	vector<int> a(w + 1);
	a[0] = a[w] = 1e9 + 5;
	for(int i = 1; i < w; ++i) {
		scanf("%d", &a[i]);
	}
	int answer = 1e9 + 5;
	int sum = 0;
	for(int i = 0; i < l; ++i) {
		sum += a[i];
	}
	answer = min(answer, sum);
	for(int i = l; i < w; ++i) {
		sum += a[i] - a[i-l];
		answer = min(answer, sum);
	}
	printf("%d\n", answer);
}