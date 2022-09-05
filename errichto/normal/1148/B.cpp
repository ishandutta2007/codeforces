#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

typedef long long ll;



int main() {
	int n, m, ta, tb, k;
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	vector<int> a(n), b(m);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		a[i] += ta;
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d", &b[i]);
	}
	int j = 0;
	int answer = 0;
	if(k >= min(n, m)) {
		puts("-1");
		return 0;
	}
	for(int i = 0; i < n; ++i) {
		while(j < m && b[j] < a[i]) {
			++j;
		}
		int rem = k - i;
		if(m - j <= rem) {
			puts("-1");
			return 0;
		}
		answer = max(answer, b[j+rem]);
		if(rem == 0) {
			break;
		}
	}
	printf("%lld\n", (long long) answer + tb);
}