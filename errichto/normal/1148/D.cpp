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
	int n;
	scanf("%d", &n);
	vector<pair<int, int>> one, two;
	for(int i = 0; i < n; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		if(a < b) {
			one.emplace_back(b, i);
		}
		else {
			two.emplace_back(a, i);
		}
	}
	if(one.size() > two.size()) {
		debug() << "one";
		sort(one.rbegin(), one.rend());
		printf("%d\n", (int) one.size());
		for(pair<int,int> p : one) {
			printf("%d ", p.second + 1);
		}
		puts("");
		return 0;
	}
	else {
		debug() << "two";
		sort(two.begin(), two.end());
		printf("%d\n", (int) two.size());
		for(pair<int,int> p : two) {
			printf("%d ", p.second + 1);
		}
		puts("");
		return 0;
	}
}