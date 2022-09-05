#include "bits/stdc++.h"
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

using ll = long long;

// 12345
// 23451
// 34512
// 45123
// 51234
// 12345
// 23451

int main() {
	int k;
	scanf("%d", &k);
	string s = "aoeui";
	for(int a = 5; a < k; ++a) {
		if(a > 5) {
			s += s[(int)s.length()-5];
		}
		int b = k / a;
		if(a * b == k && b >= 5) {
			for(int i = 0; i < b; ++i) {
				cout << s; // << endl;
				s = s.substr(1) + s[0];
			}
			cout << endl;
			return 0;
		}
	}
	puts("-1");
}