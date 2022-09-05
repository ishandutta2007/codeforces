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

using ll = long long;

int f(long long x) {
	int cnt = 0;
	while(x % 2 == 0) {
		x /= 2;
		++cnt;
	}
	return cnt;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<long long> a(n);
	vector<int> answer(100);
	for(int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
		++answer[f(a[i])];
	}
	int best = 0;
	for(int i = 0; i < 100; ++i) {
		if(answer[i] > answer[best]) {
			best = i;
		}
	}
	vector<long long> rem;
	for(int i = 0; i < n; ++i) {
		if(f(a[i]) != best) {
			rem.push_back(a[i]);
		}
	}
	printf("%d\n", (int) rem.size());
	for(long long x : rem) {
		printf("%lld ", x);
	}
	puts("");
}