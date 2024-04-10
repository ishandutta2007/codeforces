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
	int n, u, r, d, l;
	cin >> n >> u >> r >> d >> l;
	for(int bl : {0, 1}) {
		for(int br : {0, 1}) {
			for(int tl : {0, 1}) {
				for(int tr : {0, 1}) {
					auto check = [&](int remaining) {
						return 0 <= remaining && remaining <= n - 2;
					};
					if(
						check(u - tl - tr) &&
						check(d - bl - br) &&
						check(l - tl - bl) &&
						check(r - tr - br)
					) {
						cout << "YES\n";
						return;
					}
				}
			}
		}
	}
	cout << "NO\n";
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		test_case();
	}
}