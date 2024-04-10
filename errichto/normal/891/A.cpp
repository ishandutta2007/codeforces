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

const int nax = 2005;
int t[nax];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &t[i]);
	int shortest = n + 1;
	for(int i = 0; i < n; ++i) {
		int g = t[i];
		for(int j = i; j < n; ++j) {
			g = __gcd(g, t[j]);
			if(g == 1) {
				shortest = min(shortest, j - i);
			}
		}
	}
	if(shortest > n) {
		puts("-1");
		return 0;
	}
	int cnt1 = 0;
	for(int i = 0; i < n; ++i)
		if(t[i] == 1)
			cnt1++;
	int rem = n - cnt1;
	if(shortest != 0) rem--;
	int answer = shortest + rem;
	printf("%d\n", answer);
}