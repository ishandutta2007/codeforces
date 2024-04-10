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

bool test() {
	int n;
	scanf("%d", &n);
	vector<int> p(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &p[i]);
	}
	int need = 1;
	int up_to = n - 1;
	for(int i = n - 1; i >= 0; --i) {
		if(p[i] == need) {
			for(int j = i + 1; j <= up_to; ++j) {
				if(p[j] != p[j-1] + 1) {
					return false;
				}
			}
			need += up_to;
			up_to = i - 1;
			need -= up_to;
			debug() << imie(i) imie(need) imie(up_to);
		}
	}
	return true;
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		puts(test() ? "Yes" : "No");
		
	}
}