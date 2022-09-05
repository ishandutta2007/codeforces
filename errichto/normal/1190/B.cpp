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

using ll = long long;

void ONE() {
	puts("sjfnb");
	exit(0);
}
void TWO() {
	puts("cslnb");
	exit(0);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	// int moves = 0;
	sort(a.begin(), a.end());
	int where_tie = -1;
	for(int i = 0; i < n - 1; ++i) {
		if(a[i] == a[i+1]) {
			if(where_tie != -1) {
				TWO();
			}
			where_tie = i;
		}
	}
	if(where_tie != -1) {
		if(a[where_tie] == 0) {
			TWO();
		}
		if(where_tie != 0 && a[where_tie-1] == a[where_tie] - 1) {
			TWO();
		}
	}
	long long sum = 0;
	for(int x : a) {
		sum += x;
	}
	for(int i = 0; i < n; ++i) {
		sum += i;
	}
	if(sum % 2) {
		ONE();
	}
	else {
		TWO();
	}
}