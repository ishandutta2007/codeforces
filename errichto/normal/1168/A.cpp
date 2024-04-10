#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
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

typedef long long ll;



int main() {
	int n, mod;
	scanf("%d%d", &n, &mod);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	int low = 0, high = mod;
	while(low < high) {
		int diff = (low + high) / 2;
		int dp = 0; // smallest possible value of previous element
		for(int x : a) {
			int new_dp = mod;
			int up_to = min(x + diff, mod - 1);
			if(up_to >= dp) {
				new_dp = max(dp, x);
			}
			
			if(x + diff >= mod) {
				up_to = x + diff - mod;
				if(dp <= up_to) {
					new_dp = dp;
				}
			}
			dp = new_dp;
			if(dp == n) {
				break;
			}
		}
		if(dp < mod) {
			high = diff;
		}
		else {
			low = diff + 1;
		}
	}
	printf("%d\n", low);
}