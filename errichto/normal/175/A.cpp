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
	string s;
	cin >> s;
	int n = s.length();
	auto f = [&](int low, int high) {
		if(s[low] == '0' && high != low) {
			return -1;
		}
		int x = 0;
		for(int i = low; i <= high; ++i) {
			x = 10 * x + s[i] - '0';
			if(x > 1'000'000) {
				return -1;
			}
		}
		return x;
	};
	int ans = -1;
	for(int b = 1; b < n; ++b) {
		for(int c = b + 1; c < n; ++c) {
			int A = f(0, b - 1);
			int B = f(b, c - 1);
			int C = f(c, n - 1);
			if(A == -1 || B == -1 || C == -1) {
				continue;
			}
			ans = max(ans, A + B + C);
		}
	}
	printf("%d\n", ans);
}