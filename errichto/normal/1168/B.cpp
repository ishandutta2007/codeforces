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

bool ok(string s) {
	int n = s.length();
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			for(int k = j + 1; k < n; ++k) {
				if(j - i == k - j && s[i] == s[j] && s[j] == s[k]) {
					return true;
				}
			}
		}
	}
	return false;
}

const int nax = 3e5 + 5;
char sl[nax];

int main() {
	scanf("%s", sl);
	int n = strlen(sl);
	long long answer = (long long) n * (n + 1) / 2;
	for(int i = 0; i < n; ++i) {
		// string s;
		for(int j = i; j < min(n, i + 11); ++j) {
			// s += sl[j];
			bool ok = false;
			for(int k = 1; j - 2 * k >= i; ++k) {
				if(sl[j-2*k] == sl[j-k] && sl[j-k] == sl[j]) {
					ok = true;
					break;
				}
			}
			if(ok) {
				break;
			}
			--answer;	
		}
	}
	printf("%lld\n", answer);
	// int n = 10;
	// for(int mask = 0; mask < (1 << n); ++mask) {
		// string s;
		// for(int i = 0; i < n; ++i) {
			// s += '0' + bool(mask & (1 << i));
		// }
		// if(!ok(s)) {
			// debug() << imie(s);
		// }
	// }
}